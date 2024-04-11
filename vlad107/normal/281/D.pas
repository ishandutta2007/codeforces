var
  kst,i,n,ans,x:longint;
  st:array[0..500500]of longint;

begin
  read(n);
  ans:=0;
  for i:=1 to n do begin
    read(x);
    while (kst>0)and(x>st[kst])do begin
      if (x xor st[kst]>ans)then ans:=x xor st[kst];
      dec(kst);
    end;
    if (kst>0)and(x xor st[kst]>ans)then ans:=x xor st[kst];
    inc(kst);
    st[kst]:=x;
  end;
  writeln(ans);
end.