{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  ax,ay,az,a,b,h: array [0..300010] of longint;
  xx,yy,zz,tmp,ka,n,i,j,kh: longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure up(t:longint);
var
  tmp: longint;
begin
  while (t > 1) and (b[h[t]] > b[h[t shr 1]]) do
  begin
    tmp:=h[t]; h[t]:=h[t shr 1]; h[t shr 1]:=tmp;
    t:=t shr 1;
  end;
end;

procedure down(t:longint);
var
  w,tmp: longint;
begin
  while True do
  begin
    w:=t shl 1;
    if w > kh then break;
    if w < kh then
      if b[h[w+1]] > b[h[w]] then inc(w);
    if b[h[w]] > b[h[t]] then
    begin
      tmp:=h[t]; h[t]:=h[w]; h[w]:=tmp;
      t:=w;
    end
    else break;
  end;
end;

begin
  randomize;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  Sort(1,n);
  j:=1; b[1]:=1;
  for i:=2 to n do
    if a[i] = a[j] then inc(b[j]) else
    begin
      inc(j);
      a[j]:=a[i];
      b[j]:=1;
    end;
  n:=j;
  ka:=0; kh:=0;
  for i:=1 to n do
  begin
    inc(kh);
    h[kh]:=i;
    up(kh);
  end;
  while kh >= 3 do
  begin
    inc(ka);
    ax[ka]:=h[1]; h[1]:=h[kh]; dec(kh); down(1);
    ay[ka]:=h[1]; h[1]:=h[kh]; dec(kh); down(1);
    az[ka]:=h[1]; h[1]:=h[kh]; dec(kh); down(1);
    dec(b[ax[ka]]);
    dec(b[ay[ka]]);
    dec(b[az[ka]]);
    if b[ax[ka]] > 0 then begin inc(kh); h[kh]:=ax[ka]; up(kh); end;
    if b[ay[ka]] > 0 then begin inc(kh); h[kh]:=ay[ka]; up(kh); end;
    if b[az[ka]] > 0 then begin inc(kh); h[kh]:=az[ka]; up(kh); end;
  end;
  writeln(ka);
  for i:=1 to ka do
  begin
    xx:=a[ax[i]]; yy:=a[ay[i]]; zz:=a[az[i]];
    if xx < yy then begin tmp:=xx; xx:=yy; yy:=tmp; end;
    if xx < zz then begin tmp:=xx; xx:=zz; zz:=tmp; end;
    if yy < zz then begin tmp:=yy; yy:=zz; zz:=tmp; end;
    writeln(xx,' ',yy,' ',zz);
  end;
{  close(input);
  close(output);}
end.