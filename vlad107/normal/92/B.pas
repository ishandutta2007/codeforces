var
  res,i,r:longint;
  s:ansistring;
begin
  readln(s);
  res:=0;
  r:=0;
  for i:=length(s)downto 2 do
    if (s[i]='0')then begin
      if (r=1)then inc(res);
      inc(res);
    end else begin
      if (r=0)then begin
        inc(res);
	r:=1;
      end;
      inc(res);
    end;
  writeln(res+r);
end.