{$r-,q-,s-,i-,o+}
uses math;
const
  MAXN=1000000;
  INF=1000000000;
  LINF=1000000000000000000;
var
  res:int64;
  add,tm:array[1..MAXN]of int64;
  tl,tr:array[1..MAXN]of longint;
  tt,n,i,val,l,r:longint;
  function mini(x,y:int64):int64;
    begin
      if (x<y)then mini:=x else mini:=y;
    end;
  function maxi(x,y:int64):int64;
    begin
      if (x>y)then maxi:=x else maxi:=y;
    end;
  procedure build(x,l,r:longint);
    begin
      tl[x]:=l;tr[x]:=r;
      if (l<r)then begin
        build(x+x,l,(l+r)shr 1);
        build(x+x+1,(l+r)shr 1 +1,r);
      end;
    end;
  procedure modify(x,l,r:longint);
    begin
      if (l=tl[x])and(r=tr[x])
       then inc(add[x],val)
       else begin
         if (l<=tr[x+x])then modify(x+x,l,min(tr[x+x],r));
         if (r>=tl[x+x+1])then modify(x+x+1,max(l,tl[x+x+1]),r);
         tm[x]:=mini(tm[x+x]+add[x+x],tm[x+x+1]+add[x+x+1]);
       end;
    end;
  function findmin(x,l,r:longint;sa:int64):int64;
    var
      res:int64;
    begin
      if (tl[x]=l)and(tr[x]=r)
        then findmin:=tm[x]+sa
        else begin
          res:=LINF;
          if (l<=tr[x+x])then res:=mini(res,findmin(x+x,l,min(tr[x+x],r),sa+add[x+x]));
          if (r>=tl[x+x+1])then res:=mini(res,findmin(x+x+1,max(l,tl[x+x+1]),r,sa+add[x+x+1]));
          findmin:=res;
        end;
    end;
begin
  read(n);
  fillchar(add,sizeof(add),$0);
  fillchar(tm,sizeof(tm),$0);
  build(1,1,n);
  for i:=1 to n do begin
    read(val);
    modify(1,i,i);
  end;
  readln(tt);
  while (tt>0)do begin
    dec(tt);
    val:=INF;
    read(l,r);
    if (not eoln())then read(val);
    readln;
    inc(l);inc(r);
    if (val=INF)then begin
      res:=INF;
      if (l<=r)
        then res:=findmin(1,l,r,add[1])
        else res:=mini(findmin(1,l,n,add[1]),findmin(1,1,r,add[1]));
      writeln(res);
    end else begin
      if (l<=r)
        then modify(1,l,r)
        else begin
          modify(1,l,n);
          modify(1,1,r);
        end;
    end;
  end;
end.