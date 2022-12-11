var s,t:string;
    i,j,n,ans,x,y:longint;
	ch:array[0..30] of longint;
	vis:array[0..30] of boolean;
begin
  readln(s);
  readln(t);
  n:=length(s);
  fillchar(ch,sizeof(ch),0);
  for i:=1 to n do
    begin
	  x:=ord(s[i])-96;
	  y:=ord(t[i])-96;
	  if (ch[x]<>0) and (ch[x]<>y) then
	  begin
	    writeln(-1);
	    halt;
	  end;
	  if (ch[y]<>0) and (ch[x]<>y) then
	  begin
	    writeln(-1);
	    halt;
	  end;
	  ch[x]:=y;
	  ch[y]:=x;
	end;
  for i:=1 to 25 do
	for j:=i+1 to 26 do
	begin
	  if (ch[i]=j) and (ch[j]<>i) then
	  begin
	    writeln(-1);
	    halt;
	  end;
	  if (ch[j]=i) and (ch[i]<>j) then
	  begin
	    writeln(-1);
	    halt;
	  end;
	end;
  fillchar(vis,sizeof(vis),false);
  ans:=0;
  for i:=1 to 26 do
	if (ch[i]<>i) and (ch[i]<>0) then
    begin
	  inc(ans);
	  vis[i]:=true;
	end;
  writeln(ans div 2);
  for i:=1 to 26 do
	if vis[i] then
    begin
	  writeln(chr(i+96),' ',chr(ch[i]+96));
	  vis[ch[i]]:=false;
	end;
end.