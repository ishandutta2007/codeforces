var
  kst,i,n:longint;
  ans:array[0..500500]of boolean;
  st:array[0..500500]of int64;
  x,k:int64;

begin
  read(n,k);
  for i:=1 to n do begin
    read(x);
    inc(kst);
    st[kst]:=st[kst-1]+x*(kst-1);
    if (st[kst-1]-x*(n-i)*(kst-1)<k)then begin
      ans[i]:=true;
      dec(kst);
    end;
  end;
  for i:=1 to n do 
    if (ans[i])then writeln(i);
end.