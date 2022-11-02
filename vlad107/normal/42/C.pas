var
  a:array[1..10] of longint;
  p,q:array[1..100000] of longint;
  found:boolean;
  bad,i,j,ka:longint;

begin
  ka:=0;
  for i:=1 to 4 do read(a[i]);
  while (true) do begin
    found:=false;
    if (a[1]=1) and (a[2]=1) and (a[3]=1) and (a[4]=1)then break;
    for i:=1 to 4 do begin
      j:=i+1;
      if (j>4)then j:=1;
      if (a[i] mod 2=a[j] mod 2) and ((a[i]<>1) or (a[j]<>1))then begin
        found:=true;
        inc(ka);
        p[ka]:=a[i] mod 2;
        q[ka]:=i;
        if (p[ka]=1)
          then begin
            inc(a[i]);
            inc(a[j]);
          end else begin
            a[i]:=a[i] div 2;
            a[j]:=a[j] div 2;
          end;
      end;
    end;
    if (not found)then begin
      if (ka=1001)then break;
      i:=1+random(4);
      inc(ka);
      p[ka]:=1;
      q[ka]:=i;
      inc(a[i]);
      j:=i+1;
      if (j>4)then j:=1;
      inc(a[j]);
    end;
  end;
  if (a[1]=1) and (a[2]=1) and (a[3]=1) and (a[4]=1) then begin
    for i:=1 to ka do begin
      if (p[i]=1)then write('+')else write('/');
      writeln(q[i]);
    end;
  end else writeln(-1);
end.