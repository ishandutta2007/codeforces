var
  tk,ans,sk:int64;
  n,t,i,qt,j,tmp:longint;
  k,c,p:array[0..500500]of int64;

begin
  read(n);
  for i:=1 to n do read(k[i],c[i]);
  read(t);
  for i:=1 to t do read(p[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (c[j]>c[j+1])then begin
        tmp:=c[j];c[j]:=c[j+1];c[j+1]:=tmp;
        tmp:=k[j];k[j]:=k[j+1];k[j+1]:=tmp;
      end;
  qt:=1;
  sk:=0;
  i:=1;
  ans:=0;
  p[t+1]:=1000000000000000000;
  while (i<=n)do begin
    if (sk+k[i]<=p[qt])then begin
      sk:=sk+k[i];
      ans:=ans+int64(k[i])*c[i]*qt;
      inc(i);
    end else begin
      tk:=p[qt]-sk;
      ans:=ans+int64(tk)*c[i]*qt;
      sk:=sk+tk;
      k[i]:=k[i]-tk;
      inc(qt);
    end;
  end;
  writeln(ans);
end.