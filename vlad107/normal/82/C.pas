{$r-,q-,s-,i-,o+}
var
  j,n,i,x,y,z,kg,tmp:longint;
  found:boolean;
  a,t,prx,krx,res,g,pred,last,nom,now,ckr:array[0..100500]of longint;
  procedure dfs(x,px,cx:longint);
    var
      ii:longint;
    begin
      prx[x]:=px;
      krx[x]:=cx;
      ii:=last[x];
      while (ii>0)do begin
        if (g[ii]<>px)then dfs(g[ii],x,t[ii]);
        ii:=pred[ii];
      end;
    end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do nom[i]:=i;
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (a[j]>a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  kg:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(pred,sizeof(pred),$0);
  for i:=1 to n-1 do begin
    read(x,y,z);
    inc(kg);g[kg]:=y;t[kg]:=z;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;t[kg]:=z;pred[kg]:=last[y];last[y]:=kg;
  end;
  dfs(1,0,0);
  fillchar(res,sizeof(res),$0);
  found:=true;
  for i:=1 to n do now[i]:=i;
  while (found)do begin   
    found:=false;
    for i:=1 to n do begin
      ckr[i]:=0;
      if (now[nom[i]]<>1)then inc(res[nom[i]]);
    end;
    for i:=1 to n do 
      if (ckr[now[nom[i]]]<krx[now[nom[i]]])then begin
        inc(ckr[now[nom[i]]]);
        now[nom[i]]:=prx[now[nom[i]]];
        found:=true;
      end;
  end;
  for i:=1 to n do write(res[i],' ');
end.