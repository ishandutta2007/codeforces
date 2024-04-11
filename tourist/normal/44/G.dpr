{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = 1000; maxn = 100010; maxt = 3333;
var
  zz,v,ll,rr,mid,u,t1,t2,nn,r,n,m,i,x,y,j,ans: longint;
  h,t,num,x1,y1,x2,y2,z: array [0..maxn] of longint;
  b,all: array [0..maxt] of longint;
  a: array [0..3,0..maxn div co,0..maxt] of longint;
  tn: array [0..3,0..maxn] of longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=z[l+random(r-l+1)];
  repeat
    while z[i] < x do inc(i);
    while x < z[j] do dec(j);
    if i <= j then
    begin
      tmp:=x1[i]; x1[i]:=x1[j]; x1[j]:=tmp;
      tmp:=y1[i]; y1[i]:=y1[j]; y1[j]:=tmp;
      tmp:=x2[i]; x2[i]:=x2[j]; x2[j]:=tmp;
      tmp:=y2[i]; y2[i]:=y2[j]; y2[j]:=tmp;
      tmp:=z[i]; z[i]:=z[j]; z[j]:=tmp;
      tmp:=h[i]; h[i]:=h[j]; h[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure SortT(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=t[l+random(r-l+1)];
  repeat
    while t[i] < x do inc(i);
    while x < t[j] do dec(j);
    if i <= j then
    begin
      tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
      tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortT(l,j);
  if i < r then SortT(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(x1[i],x2[i],y1[i],y2[i],z[i]);
    h[i]:=i;
  end;
  Sort(1,n);
  fillchar(a,sizeof(a),0);
  nn:=n div 32;
  for r:=0 to 3 do
  begin
    for i:=1 to n do
    begin
      if r = 0 then t[i]:=-x1[i] else
      if r = 1 then t[i]:=x2[i] else
      if r = 2 then t[i]:=-y1[i]
      else t[i]:=y2[i];
      num[i]:=i;
    end;
    SortT(1,n);
    for i:=1 to n do
    begin
      if r = 0 then x1[i]:=t[i] else
      if r = 1 then x2[i]:=t[i] else
      if r = 2 then y1[i]:=t[i]
      else y2[i]:=t[i];
      tn[r,i]:=num[i];
    end;
    for j:=0 to nn do b[j]:=0;
    t1:=0; t2:=0;
    for i:=1 to n do
    begin
      j:=num[i];
      b[j shr 5]:=b[j shr 5] or (1 shl (j and 31));
      inc(t1);
      if t1 = co then
      begin
        t1:=0;
        inc(t2);
        for j:=0 to nn do a[r,t2,j]:=b[j];
      end;
    end;
  end;
  for j:=0 to nn do all[j]:=0;
  for i:=1 to n do all[i shr 5]:=all[i shr 5] or (1 shl (i and 31));
  read(m);
  for i:=1 to m do
  begin
    read(x,y);
    for j:=0 to nn do b[j]:=0;
    for r:=0 to 3 do
    begin
      if r = 0 then v:=-x else
      if r = 1 then v:=x else
      if r = 2 then v:=-y
      else v:=y;
      ll:=0; rr:=n;
      while ll < rr do
      begin
        mid:=(ll+rr+1) shr 1;
        if r = 0 then u:=x1[mid] else
        if r = 1 then u:=x2[mid] else
        if r = 2 then u:=y1[mid]
        else u:=y2[mid];
        if u < v then ll:=mid
        else rr:=mid-1;
      end;
      zz:=ll div co;
      for j:=0 to nn do b[j]:=b[j] or a[r,zz,j];
      for j:=zz*co+1 to ll do
        b[tn[r,j] shr 5]:=b[tn[r,j] shr 5] or (1 shl (tn[r,j] and 31));
    end;
    ans:=0;
    for j:=0 to nn do
      if b[j] <> all[j] then
      begin
        for v:=j shl 5 to (j shl 5)+31 do
          if (v > 0) and (b[j] or (1 shl (v and 31)) <> b[j]) then
          begin
            ans:=v;
            break;
          end;
        break;
      end;
    if ans = 0 then writeln(0) else
    begin
      writeln(h[ans]);
      for r:=0 to 3 do
        for j:=0 to n div co do
          a[r,j,ans shr 5]:=a[r,j,ans shr 5] or (1 shl (ans and 31));
    end;
  end;
  close(input);
  close(output);
end.