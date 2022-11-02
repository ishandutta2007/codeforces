var
  i,ans,d,x:longint;
  s1,s2:ansistring;
  
  procedure check(x:longint);
    begin
      str(x,s1);
      str(d,s2);
      for i:=1 to length(s1)do
        if (pos(s1[i],s2)>0)then begin
          inc(ans);
          exit;
        end;
    end;

begin
  read(d);
  ans:=0;
  for x:=1 to d do begin
    if (x*x>d)then break;
    if (d mod x=0)then begin
      check(x);
      if (x*x<>d)then check(d div x);
    end;
  end;
  writeln(ans);
end.