{$r-,q-,s-,i-,o+}
const
  maxa=1111111;

var
  tmp,kg,ii,jj,ct,ans,x,n,i,j,lst:longint;
  a,kol,g,pred,last:array[0..maxa+10]of longint;

begin
  read(n);
  ans:=0;
  for i:=1 to n do begin
    read(a[i]);
    inc(kol[a[i]]);
    if (kol[a[i]]>ans)then ans:=kol[a[i]];
  end;
  lst:=0;
  for i:=1 to maxa do
    if (kol[i]<>0)then begin
      inc(lst);
      kol[i]:=lst;
    end;
  for i:=n downto 1 do begin
    x:=kol[a[i]];
    inc(kg);
    g[kg]:=i;
    pred[kg]:=last[x];
    last[x]:=kg;
  end;
  for i:=1 to lst do 
    for j:=1 to lst do
      if (i<>j)then begin
        ii:=last[i];
        jj:=last[j];
        if (ii<>0)then ct:=1;
        while (ii>0)and(jj>0)do begin
          while (jj>0)and(g[jj]<g[ii])do jj:=pred[jj];
          if (jj=0)then break;
          inc(ct);
          tmp:=ii;ii:=jj;jj:=tmp;
        end;
        if (ct>ans)then ans:=ct;
      end;  
  writeln(ans);
end.