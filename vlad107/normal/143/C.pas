var
  r1,r2:int64;
  n,i:longint;

  procedure check2(a,b:longint);
    var
      cr:int64;
      c:longint;

    begin
      if (n mod (a*b)<>0)then exit;
      c:=n div (a*b);
      inc(a);
      inc(b,2);
      inc(c,2);
      cr:=int64(a)*b*c;
      if (cr>r2)then r2:=cr;
      if (cr<r1)then r1:=cr;
    end;          

  procedure check(a:longint);
    var
      m,i:longint;

    begin
      m:=n div a;
      i:=1;
      while (i*i<=m)do begin
        if (m mod i=0)then begin
          check2(a,i);
          check2(a,m div i);
        end;
        inc(i);
      end;
    end;

begin
  read(n);
  i:=1;
  r1:=1000000000000;
  r2:=0;
  while (i*i<=n)do begin
    if (n mod i=0)then begin
      check(i);
      check(n div i);
    end;
    inc(i);
  end;
  writeln(r1-n,' ',r2-n);
end.