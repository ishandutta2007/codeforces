var
  max,time,n,m,r,i,q,j,nn,kol:longint;
  a,b,nom,ans:array[0..11111]of longint;
begin
  read(n,m,r);
  for i:=1 to n do read(a[i],b[i]);
  q:=m;time:=-1;kol:=0;
  fillchar(ans,sizeof(ans),$FF);
  while (q>0)do begin
    inc(time);
    if (time>m*10)then begin
      writeln('NO');exit;
    end;
    inc(q,r);
    if (q>m)then q:=m;
    nn:=-1;
    max:=-1;
    for i:=1 to n do 
      if (ans[i]<0)and(a[i]*m>=100*q)and(b[i]>max)then begin
        max:=b[i];
        nn:=i;
      end;
    if (nn<0)then continue;
    if (q<=0)then break;
    inc(kol);
    ans[nn]:=time;
    dec(r,max);
  end;
  writeln('YES');
  writeln(time,' ',kol);
  for i:=1 to n do nom[i]:=i;
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (ans[j]>ans[j+1])then begin
        q:=ans[j];ans[j]:=ans[j+1];ans[j+1]:=q;
        q:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=q;
      end;
  for i:=1 to n do 
    if (ans[i]>=0)then writeln(ans[i],' ',nom[i]);
end.