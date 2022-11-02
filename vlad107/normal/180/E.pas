var
  o,kt,sum,ans,n,m,k,i,j,x,kg,ii:longint;
  t,g,pred,last:array[0..500500]of longint;

begin
  read(n,m,k);
  kg:=0;kt:=0;
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  for i:=1 to n do begin
    read(x);
    inc(kg);
    g[kg]:=i;
    pred[kg]:=last[x];
    last[x]:=kg;
  end;
  ans:=1;
  for i:=1 to m do begin
    ii:=last[i];
    kt:=0;
    while (ii>0)do begin
      inc(kt);
      t[kt]:=g[ii];
      ii:=pred[ii];
    end;
    j:=1;
    sum:=0;
    for o:=2 to kt do begin
      inc(sum,abs(t[o]-t[o-1])-1);
      while (j<o)and(sum>k)do begin
        dec(sum,abs(t[j]-t[j+1])-1);
        inc(j);
      end;
      if (o-j+1>ans)then ans:=o-j+1;
    end;
  end;
  writeln(ans);
end.