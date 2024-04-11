{$r-,q-,s-,i-,o+}
var
  x,mask,n,m,i,j,t,y:longint;
  res:int64;
  kg:array[0..20]of longint;
  r:array[0..20]of int64;
  g:array[0..20,0..20]of longint;
  f:array[0..1 shl 19,0..20]of int64;

begin
//  assign(input,'input.txt');reset(input);
  read(n,m);
  for i:=1 to m do begin
    read(x,y);
    inc(kg[x]);g[x][kg[x]]:=y;
    inc(kg[y]);g[y][kg[y]]:=x;
  end;
  fillchar(f,sizeof(f),$0);
  for i:=1 to n do f[1 shl (i-1)][i]:=1;
  for mask:=1 to 1 shl n-1 do begin
    y:=0;
    x:=mask;
    while (x>0)do begin
      inc(y);
      x:=x and (x-1);
    end;
    if (y<2)then continue;
    x:=mask;
    y:=1;
    while (x mod 2=0)do begin
      x:=x div 2;
      inc(y);
    end;
    x:=y;
    for j:=1 to n do 
      if (j<>x)and(mask and (1 shl (j-1))>0)then 
        for t:=1 to kg[j]do begin
          y:=g[j][t];
          if (mask and (1 shl (y-1))=0)then continue;
          f[mask][j]:=f[mask xor (1 shl (j-1))][y]+f[mask][j];
        end;
  end;
  res:=0;
  for mask:=1 to 1 shl n-1 do begin
    x:=mask;
    y:=0;
    while (x>0)do begin
      y:=y+1;
      x:=x and (x-1);
    end;
    if (y<3)then continue;
    x:=mask;
    y:=1;
    while (x mod 2=0)do begin
      x:=x div 2;
      inc(y);
    end;
    for j:=1 to kg[y] do 
      res:=res+f[mask][g[y][j]];
  end;
  writeln(res div 2);
end.