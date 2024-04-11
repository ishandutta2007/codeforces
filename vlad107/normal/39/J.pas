var
  res,n,i : longint;
  s,p : ansistring;
  f,g : array [0..1000100] of boolean;
  b : array [0..1000100] of longint;

begin
  readln(s);
  n := length(s);
  readln(p);
  fillchar(f,sizeof(f),false);
  fillchar(g,sizeof(g),false);
  res := 0;
  f[0] := true;
  for i:=1 to n-1 do
    if (s[i]=p[i]) then f[i] := true
    else break;
  g[n+1] := true;
  for i:=n-1 downto 1 do
    if (s[i+1]=p[i]) then g[i+1]:=true
    else break;
  for i:=1 to n do
    if (f[i-1]) and (g[i+1]) then begin
      inc(res);
      b[res] := i;
    end;
  writeln(res);
  for i:=1 to res do write(b[i], ' ');
end.