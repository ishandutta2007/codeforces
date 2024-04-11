var
  p,s:string;
  n,i,l,x:longint;
begin
  readln(s);
  n:=length(s);
  for l:=n-1 downto 1 do begin
    for i:=1 to n-l do begin
      p:=copy(s,i,l);
      x:=pos(p,s);
      if (x=0)then continue;
      if (pos(p,copy(s,x+1,length(s)))=0)then continue;
      writeln(l);
      halt(0);
    end;
  end;
  writeln(0);
end.