const andd:array[0..1,0..1] of longint=((0,0),(0,1));
	orr:array[0..1,0..1] of longint=((0,1),(1,1));
	xorr:array[0..1,0..1] of longint=((0,1),(1,0));
var n,m,i,j,k,tt,s1,s2:longint;
    ans1,ans2:array[0..1007] of longint;
	na:array[0..5007] of string;
	t:array[-1..5007,0..1007] of longint;
	op,num1,num2,tot:array[0..5007] of longint;
	now,noww:string;
	ch:char;
function find(s:string;t:longint):longint;
var left,right,mid:longint;
begin
  if (s='?') then exit(-1);
  left:=1;right:=t;
  while (right-left>1) do
  begin
    mid:=(left+right) div 2;
    if (na[mid]<s) then left:=mid else right:=mid;
  end;
  if (na[left]=s) then exit(tot[left]) else exit(tot[right]);
end;
begin
  readln(n,m);
  fillchar(t,sizeof(t),0);
  for i:=1 to n do
  begin
    tot[i]:=i;
    read(ch);na[i]:='';
    while (ch<>' ') do
	begin
	  na[i]:=na[i]+ch;
	  read(ch);
	end;
	j:=i-1;
	while (j>0) and (na[j]>na[i]) do dec(j);
	for k:=i-1 downto j+1 do
	begin
	  noww:=na[k];na[k]:=na[k+1];na[k+1]:=noww;
	  tt:=tot[k];tot[k]:=tot[k+1];tot[k+1]:=tt;
	end;
	read(ch);read(ch);read(ch);
	read(ch);
	if (ord(ch)>=ord('0')) and (ord(ch)<=ord('9')) then
	begin
	  t[i,1]:=ord(ch)-48;
	  for j:=2 to m do
	  begin
	    read(ch);
	    t[i,j]:=ord(ch)-48;
	  end;
	  readln;
	  op[i]:=-1;
	end else
	begin
	  now:='';
	  while (ch<>' ') do
	  begin
	    now:=now+ch;
	    read(ch);
	  end;
	  num1[i]:=find(now,i);
	  read(ch);
	  now:='';
	  while (ch<>' ') do
	  begin
	    now:=now+ch;
	    read(ch);
	  end;
	  if (now='OR') then op[i]:=1;
	  if (now='AND') then op[i]:=2;
	  if (now='XOR') then op[i]:=3;
      readln(now);
	  num2[i]:=find(now,i);
	end;
  end;
//for i:=1 to n do
  //writeln(op[i],' ',t[i,1],' ',num1[i],' ',num2[i]);
  for i:=1 to m do
  begin
    t[-1,i]:=0;s1:=0;
    for j:=1 to n do
	begin
	  if (op[j]>=1) then
	  begin
	    if (op[j]=1) then t[j,i]:=orr[t[num1[j],i],t[num2[j],i]];
		if (op[j]=2) then t[j,i]:=andd[t[num1[j],i],t[num2[j],i]];
		if (op[j]=3) then t[j,i]:=xorr[t[num1[j],i],t[num2[j],i]];
	  end;
	  s1:=s1+t[j,i];
	end;
	t[-1,i]:=1;s2:=0;
    for j:=1 to n do
	begin
	  if (op[j]>=1) then
	  begin
	    if (op[j]=1) then t[j,i]:=orr[t[num1[j],i],t[num2[j],i]];
		if (op[j]=2) then t[j,i]:=andd[t[num1[j],i],t[num2[j],i]];
		if (op[j]=3) then t[j,i]:=xorr[t[num1[j],i],t[num2[j],i]];
	  end;
	  s2:=s2+t[j,i];
	end;
	if (s1<=s2) then ans1[i]:=0 else ans1[i]:=1;
	if (s1>=s2) then ans2[i]:=0 else ans2[i]:=1;
  end;
  for i:=1 to m do
	write(ans1[i]);
  writeln;
  for i:=1 to m do
	write(ans2[i]);
  writeln;
end.