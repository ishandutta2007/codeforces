{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  m,i,md: longint;
  n,l,r,u,v,ans: int64;

function find(l,r,x,y,ll,rr,u,v:int64):int64;
var
  ans,q,first,last,cnt: int64;
begin
  if (r < ll) or (rr < l) then
  begin
    find:=0;
    exit;
  end;
  if (l >= ll) and (r <= rr) then
  begin
    ans:=0;
    q:=u mod y;
    if q <= x then first:=u+(x-q)
    else first:=u+(y-q)+x;
    if first <= v then
    begin
      last:=first+(v-first) div y*y;
      cnt:=(last-first) div y+1;
      x:=first+last+2;
      y:=cnt;
      if x and 1 = 0 then x:=x shr 1
      else y:=y shr 1;
      x:=x mod md;
      y:=y mod md;
      ans:=x*y mod md;
    end;
    find:=ans;
    exit;
  end;
  q:=find(l,(l+r) shr 1,x,y+y,ll,rr,u,v);
  q:=q+find((l+r) shr 1+1,r,x+y,y+y,ll,rr,u,v);
  find:=q mod md;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m,md);
  for i:=1 to m do
  begin
    read(l,r,u,v);
    if v > n then v:=n;
    dec(u); dec(v);
    ans:=find(1,n,0,1,l,r,u,v);
    writeln(ans);
  end;
  close(input);
  close(output);
end.