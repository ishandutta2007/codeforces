var
  a,t:array[0..50]of string;
  tmp,sx,sy,s:string;
  kx,kt,n,m,i,j,max,nom,x,y,mask:longint;
  ok:boolean;
  g:array[0..50,0..50]of boolean;

  function fnom(s:string):longint;
    var
      i:longint;

    begin
      i:=1;
      while (a[i]<>s)do inc(i);
      fnom:=i;
    end;

begin
  readln(n,m);
  for i:=1 to n do readln(a[i]);
  for i:=1 to m do begin
    readln(s);
    sx:=copy(s,1,pos(' ',s)-1);
    sy:=s;
    delete(sy,1,pos(' ',sy));
    x:=fnom(sx);
    y:=fnom(sy);
    g[x][y]:=true;
    g[y][x]:=true;
  end;
  max:=0;                                                                  
  nom:=0;
  for mask:=1 to 1 shl n-1 do begin
    ok:=true;
    for i:=1 to n do 
      for j:=1 to n do
        if (mask and (1 shl (i-1))>0)and
           (mask and (1 shl (j-1))>0)and
           (g[i][j])then ok:=false;
    if (not ok)then continue;
    kx:=0;
    x:=mask;
    while (x>0)do begin
      inc(kx);
      x:=x and (x-1);
    end;
    if (kx>max)then begin
      max:=kx;
      nom:=mask;
    end;
  end;
  kt:=0;
  for i:=1 to n do 
    if (nom and (1 shl (i-1))>0)then begin
      inc(kt);
      t[kt]:=a[i];
    end;
  for i:=1 to kt-1 do 
    for j:=1 to kt-1 do
      if (t[j]>t[j+1])then begin
        tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
      end; 
  writeln(kt);
  for i:=1 to kt do writeln(t[i]);
end.