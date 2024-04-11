const deal:array[1..6] of string=('S','M','L','XL','XXL','XXXL');
var n,i,j,tot:longint;
    ts,ss:string;
	ans,first,second:array[1..100000] of longint;
	s:array[1..6] of longint;
function tryit(s:string):longint;
begin
  if (s='S') then exit(1);
  if (s='M') then exit(2);
  if (s='L') then exit(3);
  if (s='XL') then exit(4);
  if (s='XXL') then exit(5);
  if (s='XXXL') then exit(6);
end;
begin
  fillchar(s,sizeof(s),0);
  fillchar(ans,sizeof(ans),0);
  fillchar(first,sizeof(first),0);
  fillchar(second,sizeof(second),0);
  for i:=1 to 6 do
	read(s[i]);
  readln;
  readln(n);
  for i:=1 to n do
  begin
    readln(ss);
    tot:=0;
    for j:=1 to length(ss) do
	  if (ss[j]=',') then tot:=j;
	if (tot=0) then first[i]:=tryit(ss)
	else
	begin
	  ts:='';
	  for j:=1 to tot-1 do
		ts:=ts+ss[j];
	  first[i]:=tryit(ts);
	  ts:='';
	  for j:=tot+1 to length(ss) do
		ts:=ts+ss[j];
	  second[i]:=tryit(ts);
	end;
  end;
  for i:=1 to n do
  begin
    if (second[i]=0) then
    begin
	  if (s[first[i]]=0) then
	  begin
	    writeln('NO');
	    halt;
	  end
	  else
	  begin
	    dec(s[first[i]]);
	    ans[i]:=first[i];
	  end;
	end;
  end;
  for i:=1 to 6 do
  begin
    for j:=1 to n do
		if (ans[j]=0) and (second[j]=i) and (s[i]>0) then
		begin
		  dec(s[i]);
		  ans[j]:=i;
		end;
	for j:=1 to n do
		if (ans[j]=0) and (first[j]=i) and (s[i]>0) then
		begin
		  dec(s[i]);
		  ans[j]:=i;
		end;
  end;
  for i:=1 to n do
	if (ans[i]=0) then
	begin
	  writeln('NO');
	  halt;
	end;
  writeln('YES');
  for i:=1 to n do
	writeln(deal[ans[i]]);
end.