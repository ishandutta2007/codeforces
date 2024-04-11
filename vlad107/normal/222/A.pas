{$r-,q-,s-,i-,o+}
var
  n,k,i,ck,qb,qe:longint;
  kol,a:array[0..500500]of longint;

begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  ck:=0;
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to n do begin
    inc(kol[a[i]]);
    if (kol[a[i]]=1)then inc(ck);
  end;
  qb:=0;qe:=n;
  if (ck=1)then begin
    writeln(0);
    exit;
  end;
  for i:=1 to 2*n do begin
    inc(qe);
    a[qe]:=a[qb+k];
    inc(kol[a[qe]]);
    if (kol[a[qe]]=1)then inc(ck);
    inc(qb);
    dec(kol[a[qb]]);
    if (kol[a[qb]]=0)then dec(ck);
    if (ck=1)then begin
      writeln(i);
      exit;
    end;
  end;
  writeln(-1);
end.