{$r-,q-,s-,i-,o+}
var
  t,l,r,q,res:int64;
  j,i:longint;
  procedure check(x,q:int64);
    var
      i:int64;
      k:longint;
    begin
      i:=x;
      k:=0;
      while (i>0)do begin
        k:=k+1;
        i:=i div 10;
      end;
      i:=q;
      while (i>0)do begin
        k:=k-1;
        i:=i div 10;
      end;
      if (k<>0)then exit;
      if (x*(q-x)>res)then res:=x*(q-x);
    end;
begin
  read(l,r);
  q:=1;
  res:=0;
  for i:=1 to 10 do begin
    q:=q*10;
    check(l,q-1);
    check(r,q-1);
    for j:=-100 to 100 do begin
      t:=(q div 2)+j;
      if (t>=l)and(t<=r)then check(t,q-1);
    end;
  end;
  writeln(res);
end.