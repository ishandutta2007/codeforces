var
  s,p:ansistring;
  ls,lp,x,y,i:longint;
  ch:char;

begin
  readln(s);
  readln(p);
  ls:=length(s);
  lp:=length(p);
  if (ls<>lp)then begin
    writeln('NO');
    exit;
  end;
  x:=-1;y:=-1;
  for i:=1 to length(s) do 
    if (s[i]<>p[i])then begin
      if (x=-1)then x:=i else
      if (y=-1)then y:=i else begin
        writeln('NO');
        exit;
      end;
    end;
  if (x=-1)or(y=-1)then begin
    writeln('NO');
    exit;
  end;
  ch:=s[x];s[x]:=s[y];s[y]:=ch;
  if (s<>p)
    then writeln('NO')
    else writeln('YES');
end.