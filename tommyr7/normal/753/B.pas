var x,y,z,w,a,b,i:longint;
    s,now:array[1..4] of longint;
	vis:array[1..4] of boolean;
procedure tryit(u:longint);
var i:longint;
begin
  if (u>4) then
  begin
    for i:=1 to 4 do
		write(now[i]);
	writeln;
	flush(output);
	readln(a,b);
	if (a=4) then halt;
  end
	else
		begin
  for i:=1 to 4 do
	if not(vis[s[i]]) then
	begin
	  vis[s[i]]:=true;
	  now[u]:=s[i];
	  tryit(u+1);
	  now[u]:=0;
	  vis[s[i]]:=false;
	end;
	end;
end;
begin
  x:=-1;y:=-1;z:=-1;w:=-1;
  for i:=0 to 9 do
  begin
    writeln(i,i,i,i);
    flush(output);
    readln(a,b);
    if (a+b>0) then
    begin
	  if (x=-1) then x:=i
	  else if (y=-1) then y:=i
	  else if (z=-1) then z:=i
	  else if (w=-1) then w:=i;
	end;
  end;
  s[1]:=x;s[2]:=y;s[3]:=z;s[4]:=w;
  fillchar(vis,sizeof(vis),false);
  fillchar(now,sizeof(now),0);
  tryit(1);
end.