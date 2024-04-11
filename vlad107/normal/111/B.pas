var
  last:array[0..500500]of longint;
  x,y,i,n,res,ii:longint;

  procedure check(x:longint);
    begin
      if (last[x]<i-y)then inc(res);
      last[x]:=i;
    end;

begin
  read(n);
  fillchar(last,sizeof(last),$0);
  for i:=1 to n do begin
    read(x,y);
    ii:=1;
    res:=0;
    while (ii*ii<=x)do begin
      if (x mod ii=0)then begin
        check(ii);
        if (ii*ii<>x)then check(x div ii);
      end;    
      inc(ii);
    end;
    writeln(res);
  end;
end.