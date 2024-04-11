{$r-,q-,s-,i-,o+}
const
  base=1000000007;

var
  n,k,i,j,cr,ans:longint;
  f,a:array[0..500500]of longint;
  
  function pow(x,y:longint):longint;
    var
      res,ct:longint;
      
    begin
      res:=1;ct:=x;
      while (y>0)do begin
        if (y and 1=1)then res:=int64(res)*ct mod base;
        ct:=int64(ct)*ct mod base;
        y:=y shr 1;
      end;
      pow:=res;
    end;
  
  function kol(x1,y1,x2,y2:longint):longint;
    begin
      x2:=x2-x1;y2:=y2-y1;
      kol:=f[y2];
    end;
    
  function c(n,k:longint):longint;
    var
      res,cr,i:longint;
      
    begin
      res:=1;
      for i:=n-k+1 to n do res:=int64(res)*i mod base;
      cr:=1;
      for i:=1 to k do cr:=int64(cr)*i mod base;
      c:=int64(res)*pow(cr,base-2)mod base;
    end;

begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  if (k=0)then begin
    for i:=1 to n do write(a[i],' ');
    writeln;
    exit;
  end;
  for i:=0 to n-1 do f[i]:=c(k-1+i,i);
  for i:=1 to n do begin
    ans:=0;
    for j:=1 to i do begin
      cr:=kol(1,j,k,i);
      ans:=ans+(int64(cr)*a[j])mod base;
      if (ans>=base)then dec(ans,base);
    end;
    write(ans,' ');
  end;
  writeln;
end.