{$r-,q-,s-,i-,o+}
const
  el:array[1..100]of string=('H', 'He', 'Li', 'Be', 'B', 'C', 'N', 'O', 'F', 'Ne', 'Na', 'Mg', 'Al', 'Si', 'P', 'S', 'Cl', 'Ar', 'K', 'Ca',
                             'Sc', 'Ti', 'V', 'Cr', 'Mn', 'Fe', 'Co', 'Ni', 'Cu', 'Zn', 'Ga', 'Ge', 'As', 'Se', 'Br', 'Kr', 'Rb', 'Sr', 'Y',
                             'Zr', 'Nb', 'Mo', 'Tc', 'Ru', 'Rh', 'Pd', 'Ag', 'Cd', 'In', 'Sn', 'Sb', 'Te', 'I', 'Xe', 'Cs', 'Ba', 'La', 'Ce',
                             'Pr', 'Nd', 'Pm', 'Sm', 'Eu', 'Gd', 'Tb', 'Dy', 'Ho', 'Er', 'Tm', 'Yb', 'Lu', 'Hf', 'Ta', 'W', 'Re', 'Os', 'Ir',
                             'Pt', 'Au', 'Hg', 'Tl', 'Pb', 'Bi', 'Po', 'At', 'Rn', 'Fr', 'Ra', 'Ac', 'Th', 'Pa', 'U', 'Np', 'Pu', 'Am', 'Cm',
                             'Bk', 'Cf', 'Es', 'Fm');
var
  a,b:array[0..20]of longint;
  g,f:array[0..20,0..200500]of longint;
  kg:array[0..20]of longint;
  t,kol,j,m,n,i,nom,x,mask:longint;
  q,s:ansistring;
  procedure rec(x,k,mask:longint);
    begin
      if (k>b[nom])then exit;
      if (x>n)then begin
        if (k<>b[nom])then exit;
        inc(kg[nom]);
        g[nom][kg[nom]]:=mask;
        exit;
      end;
      rec(x+1,k,mask);
      rec(x+1,k+a[x],mask or (1 shl (x-1)));
    end;
begin
  readln(n,m);
  readln(s);
  s:=s+' ';
  for i:=1 to n do begin
    q:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    x:=1;
    while (el[x]<>q)do inc(x);
    a[i]:=x;
  end;
  readln(s);
  s:=s+' ';
  for i:=1 to m do begin
    q:=copy(s,1,pos(' ',s)-1);
    delete(s,1,pos(' ',s));
    x:=1;
    while (el[x]<>q)do inc(x);
    b[i]:=x;
  end;
  for i:=1 to m do begin
    nom:=i;
    kg[i]:=0;
    rec(1,0,0);
  end;
  fillchar(f,sizeof(f),$FF);
  f[1][0]:=0;
  for i:=1 to m do
    for mask:=0 to 1 shl n-1 do if (f[i][mask]<>-1)then
      for j:=1 to kg[i] do
        if (mask and g[i][j]=0)then f[i+1][mask+g[i][j]]:=g[i][j];
  if (f[m+1][1 shl n-1]=-1)then begin
    writeln('NO');
    exit;
  end;
  writeln('YES');
  i:=m+1;
  mask:=1 shl n-1;
  while (i<>1)do begin
    j:=f[i][mask];
    kol:=0;
    for t:=1 to n do
      if(j and (1 shl (t-1))>0)then inc(kol);
    for t:=1 to n do
      if (j and (1 shl (t-1))>0)then begin
        write(el[a[t]]);
        dec(kol);
        if (kol>0)then write('+');
      end;
    dec(i);
    dec(mask,j);
    writeln('->',el[b[i]]);
  end;
end.