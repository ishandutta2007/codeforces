uses math;
var n,i,j,a1,a2,a3,a4,ans:longint;
    ch:array[0..100007] of char;
begin
  n:=0;
  while not(eoln) do
  begin
    inc(n);
    read(ch[n]);
  end;
  readln;
  if (n mod 2=1) then writeln(-1) else
  begin
    a1:=0;a2:=0;a3:=0;a4:=0;
    for i:=1 to n do
	  if (ch[i]='L') then inc(a1)
	  else if (ch[i]='R') then inc(a2)
	  else if (ch[i]='U') then inc(a3)
	  else if (ch[i]='D') then inc(a4);
	ans:=abs(a1-a2) div 2;
	ans:=ans+abs(a4-a3) div 2;
	if ((a1+a2) mod 2=1) then inc(ans);
	writeln(ans);
  end;
end.