{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  key,sum: array [0..200010] of int64;
  pv,ver,id,leaf,pred,de,w,left,right,last,ll,lr,rl,rr: array [0..200010] of longint;
  ii,tt,qq,lo,hi,mid,val,from,kw,n,root,i,nl: longint;

procedure rec(v,depth:longint);
var
  j: longint;
begin
  inc(kw);
  w[kw]:=v;
  left[v]:=0;
  right[v]:=0;
  de[v]:=depth;
  j:=last[v];
  while j > 0 do
  begin
    if key[j] < key[v] then left[v]:=j
    else right[v]:=j;
    rec(j,depth+1);
    j:=pred[j];
  end;
  if left[v] = 0 then
  begin
    ll[v]:=v;
    lr[v]:=v;
    rl[v]:=v;
    rr[v]:=v;
  end else
  begin
    ll[v]:=ll[left[v]];
    lr[v]:=rr[left[v]];
    rl[v]:=ll[right[v]];
    rr[v]:=rr[right[v]];
  end;
end;

procedure rec2(v:longint);
begin
  if left[v] = 0 then
  begin
    inc(nl);
    leaf[nl]:=v;
    id[v]:=nl;
  end else
  begin
    rec2(left[v]);
    rec2(right[v]);
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  root:=0;
  for i:=1 to n do
  begin
    read(pv[i],key[i]);
    if pv[i] = -1 then root:=i else
    begin
      pred[i]:=last[pv[i]];
      last[pv[i]]:=i;
    end;
  end;
  kw:=0;
  rec(root,0);
  for ii:=2 to kw do
  begin
    i:=w[ii];
    if left[pv[i]] = i then sum[i]:=sum[pv[i]]+key[rl[pv[i]]]
    else sum[i]:=sum[pv[i]]+key[lr[pv[i]]];
  end;
  nl:=0;
  rec2(root);
  for i:=1 to n do
    if left[i] > 0 then ver[id[lr[i]]]:=i;
  read(tt);
  for qq:=1 to tt do
  begin
    read(val);
    lo:=0; hi:=nl;
    while lo < hi do
    begin
      mid:=(lo+hi+1) shr 1;
      if key[leaf[mid]] < val then lo:=mid
      else hi:=mid-1;
    end;
    if lo = 0 then from:=1 else
    if hi = nl then from:=nl else
    if val < key[ver[lo]] then from:=lo
    else from:=lo+1;
    writeln(sum[leaf[from]]/de[leaf[from]]:0:17);
  end;
  close(input);
  close(output);
end.