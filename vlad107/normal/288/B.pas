{$r-,q-,s-,i-,o+}
const
  base=1000000007;

var
  qqq,res,n,k,i:longint;
  p,used:array[0..500500]of longint;
  u:array[0..500500]of boolean;
  
  function can(x:longint):boolean;
    begin
      if (x=1)or(used[x]=qqq)then begin
        can:=u[x] or (x=1);
        exit;
      end;
      used[x]:=qqq;
      u[x]:=false;
      u[x]:=can(p[x]);
      can:=u[x];
    end;

  procedure rec(x:longint);
    var
      i:longint;
    begin
      if (x>k)then begin
        inc(qqq);
        for i:=2 to k do if (not can(i))then exit;
        res:=res+1;
        exit;
      end;
      for i:=1 to k do begin
        p[x]:=i;
        rec(x+1);
        p[x]:=0;
      end;
    end;

begin
  read(n,k);
  res:=0;
  rec(2);
  for i:=k+1 to n do res:=int64(res)*(n-k)mod base;
  res:=int64(res)*k mod base;
  writeln(res);
end.