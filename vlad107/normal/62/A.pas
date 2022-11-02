var
  min,max,al,ar,bl,br:longint;
  function ok(l,r:longint):boolean;
    begin
      min:=l-1;
      max:=2*(l+1);
      ok:=(r>=min)and(r<=max);
    end;
begin
  read(al,ar,bl,br);
  if (ok(ar,bl))or(ok(al,br))
    then writeln('YES')
    else writeln('NO');
end.