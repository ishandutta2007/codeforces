{$r-,q-,s-,i-,o+}
var
  s:ansistring;
  n,i,j,cr,y,tx:longint;
  a:array[0..1005000]of longint;
  pf,f:array[0..1005000,0..1]of longint;

begin
  readln(s);
  n:=length(s);
  for i:=1 to n do a[i]:=ord(s[i])-48;

  fillchar(f,sizeof(f),$FF);
  f[1][0]:=3-a[1];
  f[1][1]:=a[1];
  for i:=1 to n-1 do
    for j:=0 to 1 do
      if (f[i][j]<>-1)then begin
        cr:=f[i][j]+a[i+1];
        if (f[i+1][1]=-1)or(cr<f[i+1][1])then begin
          f[i+1][1]:=cr;
          pf[i+1][1]:=j;
        end;

        cr:=f[i][j]+1-a[i+1];
        if (j=1)then inc(cr,2);

        if (f[i+1][0]=-1)or(cr<f[i+1][0])then begin
          f[i+1][0]:=cr;
          pf[i+1][0]:=j;
        end;
      end;
  if (f[n][1]<f[n][0])then y:=1 else y:=0;
  writeln(f[n][y]);
  i:=n;
  tx:=-1;
  while (i>0)do begin
    inc(tx);
    if (y=1)then begin
      if (a[i]=1)then writeln('+2^',tx);
      y:=pf[i][y];
      dec(i);
      continue;
    end;
    writeln('-2^',tx);

    while (i>1)and(pf[i][y]=0)do begin
      y:=pf[i][y];
      dec(i);
      inc(tx);
      if (a[i]=0)then writeln('-2^',tx);
    end;
    writeln('+2^',tx+1);
    y:=pf[i][y];
    dec(i);
  end;
end.