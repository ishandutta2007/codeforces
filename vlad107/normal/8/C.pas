{$r-,q-,s-,i-,o+}
var
  cr,x0,y0,n,i,full,j,q,mm,mask,cd:longint;
  pred,f:array[0..1 shl 24]of longint;
  r,x,y:array[0..111]of longint;
begin
  read(x0,y0);
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  full:=(1 shl n)-1;
  for i:=0 to full do f[i]:=maxlongint;
  f[0]:=0;
  for mask:=0 to full do begin
    if (f[mask]>=f[full])then continue;
    for j:=1 to n do if (mask and (1 shl (j-1))=0)then begin
      for q:=j to n do begin
        if (mask and (1 shl (q-1))>0)then continue;
        cd:=(x0-x[j])*(x0-x[j])+(y0-y[j])*(y0-y[j])+
            (x[j]-x[q])*(x[j]-x[q])+(y[j]-y[q])*(y[j]-y[q])+
            (x0-x[q])*(x0-x[q])+(y0-y[q])*(y0-y[q]);
        mm:=(mask or (1 shl (j-1))) or (1 shl (q-1));
        if (f[mask]+cd<f[mm])then begin
          f[mm]:=f[mask]+cd;
          pred[mm]:=mask;
        end;
      end;
      break;
    end;
  end;
  writeln(f[full]);
  i:=full;
  cr:=0;
  while (i>0)do begin
    inc(cr);
    r[cr]:=0;
    q:=i xor pred[i];
    for j:=1 to n do
      if (q and (1 shl (j-1))>0)
        then begin
          inc(cr);
          r[cr]:=j;
        end;
    i:=pred[i];
  end;
  write(0);
  for i:=cr downto 1 do write(' ',r[i]);
end.