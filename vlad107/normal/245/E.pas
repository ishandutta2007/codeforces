var
  k0,k1,ans,balance,i:longint;
  s:ansistring;

begin
  readln(s);
  k0:=0;k1:=0;ans:=0;
  for i:=1 to length(s)do begin
    if (s[i]='-')then begin
      if (k1=0)then inc(ans) else dec(k1);
      inc(k0);
    end else begin
      if (k0=0)then inc(ans)else dec(k0);
      inc(k1);
    end;
  end;
  writeln(ans);
end.