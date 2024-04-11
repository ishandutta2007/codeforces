{$r-,q-,s-,i-,o+}
{$M 10000000}
const  
  maxn=1000000000;
var
  tmp,i,j,ll,rr,lx,rx,l1,r1,l2,r2,k,ka:longint;
  a:array[0..10005]of int64;
  aa,bb:int64;
  procedure rec(x:longint);
    begin
      if (x>maxn)then exit;
      inc(ka);
      a[ka]:=x;
      if (int64(x)*10<=maxn)then begin
        rec(x*10+4);
        rec(x*10+7);
      end;
    end;
  function cross(l1,r1,l2,r2:longint):longint;
    var
      tmp:longint;
    begin
      if (l1>l2)or(l1=l2)and(r1<r2)then begin
        tmp:=l1;l1:=l2;l2:=tmp;
        tmp:=r1;r1:=r2;r2:=tmp;
      end;
      if (r1<l2)then begin
        cross:=0;
        exit;
      end;
      if (r1>=r2)then begin
        cross:=r2-l2+1;
        exit;
      end;
      cross:=r1-l2+1;
    end;
begin
  read(l1,r1,l2,r2,k);
  ka:=0;
  rec(4);
  rec(7);
  //writeln(ka);
  for i:=1 to ka-1 do 
    for j:=1 to ka-1 do 
      if (a[j]>a[j+1])then begin 
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  aa:=0;
  bb:=int64(r1-l1+1)*(r2-l2+1);
  a[ka+1]:=1000000001;
  a[0]:=0;
  for i:=1 to ka-k+1 do begin
    j:=i+k-1;
    ll:=a[i-1]+1;
    rr:=a[i];
    lx:=a[j];
    rx:=a[j+1]-1;
    aa:=aa+int64(cross(ll,rr,l1,r1))*cross(lx,rx,l2,r2);
    aa:=aa+int64(cross(lx,rx,l1,r1))*cross(ll,rr,l2,r2);
    if (cross(a[i],a[i],l1,r1)>0)and(cross(a[i],a[i],l2,r2)>0)and(k=1)
      then aa:=aa-1;
  end;
  writeln(aa/bb:0:10);
end.