var
  i,j,n,m,x,kst,u:longint;
  a,b,ans,s1,s2:array[0..500500]of longint;

begin
  read(n,m);
  for i:=1 to n do begin
    read(x);inc(a[x]);
  end;
  for i:=1 to n do begin
    read(x);
    inc(b[x]);
  end;
  kst:=0;
  for i:=0 to m-1 do begin
    for j:=1 to a[i] do begin inc(kst);s1[kst]:=i;s2[kst]:=1;end;
    u:=m-i-1;
    for j:=1 to b[u] do 
      if (kst>0)and(s2[kst]=1)then begin
        inc(ans[s1[kst]+u]);
        dec(kst);
      end else begin
        inc(kst);
        s1[kst]:=u;
        s2[kst]:=2;
      end;
  end;
  for i:=1 to kst div 2 do inc(ans[(s1[i]+s1[kst-i+1])mod m]);
  for i:=m-1 downto 0 do for j:=1 to ans[i] do write(i,' ');
  writeln;
end.