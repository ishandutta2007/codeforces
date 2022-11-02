var
  u,i,k,n,qt:longint;
  a,t:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  k:=0;qt:=0;
  for i:=1 to n do 
    if (i>1)and(a[i]=a[i-1])then inc(k) else begin
      u:=a[i-1];
      while (k>0)and(u<>a[i])do begin
        if (k and 1=1)then begin
          inc(qt);
          t[qt]:=u;
        end;
        k:=k shr 1;
        inc(u);
      end;
      inc(k);
    end;
  u:=a[i];
  while (k>0)do begin
    if (k and 1=1)then begin
      inc(qt);
      t[qt]:=u;
    end;
    k:=k shr 1;
    inc(u);
  end;
  writeln(t[qt]+1-qt);
end.