{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  d,x1,y1,x2,y2,ans,cur,cnt,tmp,xx,yy,n,kminx,kminy,kmaxx,kmaxy,i,ll,rr,mid: longint;
  ok: boolean;
  x,y: array [0..5555] of longint;

function cover(x1,y1,x2,y2,d:longint):boolean;
var
  i: longint;
begin
  ok:=True;
  for i:=1 to n do
    if (x[i] >= x1) and (x[i] <= x1+d) and (y[i] >= y1) and (y[i] <= y1+d) then ok:=True else
    if (x[i] >= x2) and (x[i] <= x2+d) and (y[i] >= y2) and (y[i] <= y2+d) then ok:=True else
    begin
      ok:=False;
      break;
    end;
  cover:=ok;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  kminx:=1;
  kminy:=1;
  kmaxx:=1;
  kmaxy:=1;
  for i:=1 to n do
  begin
    read(xx,yy);
    x[i]:=xx-yy;
    y[i]:=xx+yy;
    if x[i] < x[kminx] then kminx:=i;
    if x[i] > x[kmaxx] then kmaxx:=i;
    if y[i] < y[kminy] then kminy:=i;
    if y[i] > y[kmaxy] then kmaxy:=i;
  end;
  if x[kmaxx]-x[kminx] > y[kmaxy]-y[kminy] then
  begin
    for i:=1 to n do
    begin
      tmp:=x[i]; x[i]:=y[i]; y[i]:=tmp;
    end;
    tmp:=kminx; kminx:=kminy; kminy:=tmp;
    tmp:=kmaxx; kmaxx:=kmaxy; kmaxy:=tmp;
  end;
  ll:=0; rr:=y[kmaxy]-y[kminy];
  while ll < rr do
  begin
    mid:=(ll+rr) shr 1;
    ok:=False;
    ok:=ok or cover(x[kminx],y[kminy],x[kmaxx]-mid,y[kmaxy]-mid,mid);
    ok:=ok or cover(x[kmaxx]-mid,y[kminy],x[kminx],y[kmaxy]-mid,mid);
    if ok then rr:=mid
    else ll:=mid+1;
  end;
  d:=ll;
  writeln(d);
  if y[kmaxy]-y[kminy] <= d then
  begin
    ans:=1;
    for i:=1 to n do ans:=ans*2 mod md;
    writeln(ans);
  end else
  if x[kmaxx]-x[kminx] <= d then
  begin
    ans:=2;
    for i:=1 to n do
      if (y[i] <= y[kminy]+d) and (y[i] >= y[kmaxy]-d) then ans:=ans*2 mod md;
    writeln(ans);
  end else
  begin
    x1:=x[kminx]; y1:=y[kminy];
    x2:=x[kmaxx]-d; y2:=y[kmaxy]-d;
    cur:=2;
    for i:=1 to n do
    begin
      cnt:=0;
      if (x[i] >= x1) and (x[i] <= x1+d) and (y[i] >= y1) and (y[i] <= y1+d) then inc(cnt);
      if (x[i] >= x2) and (x[i] <= x2+d) and (y[i] >= y2) and (y[i] <= y2+d) then inc(cnt);
      cur:=cur*cnt mod md;
    end;
    ans:=cur;
    x1:=x[kmaxx]-d; y1:=y[kminy];
    x2:=x[kminx]; y2:=y[kmaxy]-d;
    cur:=2;
    for i:=1 to n do
    begin
      cnt:=0;
      if (x[i] >= x1) and (x[i] <= x1+d) and (y[i] >= y1) and (y[i] <= y1+d) then inc(cnt);
      if (x[i] >= x2) and (x[i] <= x2+d) and (y[i] >= y2) and (y[i] <= y2+d) then inc(cnt);
      cur:=cur*cnt mod md;
    end;
    ans:=(ans+cur) mod md;
    writeln(ans);
  end;
  close(input);
  close(output);
end.