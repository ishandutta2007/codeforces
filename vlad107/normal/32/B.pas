var
  res,s:ansistring;
  i:longint;
begin
  readln(s);
  i:=1;
  res:='';
  while (i<=length(s))do begin
    if (s[i]='.')then begin
      inc(i);
      res:=res+'0';
    end else 
    if (s[i]+s[i+1]='-.')then begin
      inc(i,2);
      res:=res+'1';
    end else begin
       inc(i,2);
       res:=res+'2';
    end;
  end;
  writeln(res);
end.