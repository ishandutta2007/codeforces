
var
  ans:int64;
  o1,o2,nom,cnt,prx,pred,last,pred2,last2,g,g2,p,p2,sumt,kolv:array[0..500500]of longint;
  ii,n,kg,kg2,i,x,y,z,m:longint;

  procedure dfs(x,px:longint);
    var
      ii,z,y:longint;
      
    begin
      sumt[x]:=0;
      kolv[x]:=1;
      prx[x]:=px;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        z:=p[ii];
        if (y<>px)then begin
          dfs(y,x);
          inc(sumt[y],2*z);
          inc(sumt[x],sumt[y]);
          inc(kolv[x],kolv[y]);
        end;
        ii:=pred[ii];
      end;
    end;
    
  procedure qs(l,r:longint);
    var
      nn,i,j,xx,yy,tmp:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=o1[nn];
      yy:=o2[nn];
      while (i<=j)do begin
        while (int64(xx)*o2[i]>int64(o1[i])*yy)do inc(i);
        while (int64(xx)*o2[j]<int64(o1[j])*yy)do dec(j);
        if (i>j)then break;
        tmp:=o1[i];o1[i]:=o1[j];o1[j]:=tmp;
        tmp:=o2[i];o2[i]:=o2[j];o2[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        tmp:=cnt[i];cnt[i]:=cnt[j];cnt[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
    
  procedure dfs2(x,time:longint);
    var
      ii,y,z:longint;
      
    begin
      ans:=ans+time;
      ii:=last2[x];
      while (ii>0)do begin
        y:=g2[ii];
        z:=p2[ii];
        dfs2(y,time+z);
        inc(time,sumt[y]);
        ii:=pred2[ii];
      end;
    end;

begin
  randomize;
  read(n);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(last2,sizeof(last2),$0);
  for i:=1 to n-1 do begin
    read(x,y,z);
    inc(kg);g[kg]:=y;p[kg]:=z;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;p[kg]:=z;pred[kg]:=last[y];last[y]:=kg;
  end;
  dfs(1,0);
  kg2:=0;
  for x:=1 to n do begin
    ii:=last[x];
    m:=0;
    while (ii>0)do begin
      y:=g[ii];
      z:=p[ii];
      if (y<>prx[x])then begin
        inc(m);
        nom[m]:=y;
        cnt[m]:=z;
        o1[m]:=sumt[y];
        o2[m]:=kolv[y];
      end;
      ii:=pred[ii];
    end;
    qs(1,m);
    for i:=m downto 1 do begin
      y:=nom[i];
      z:=cnt[i];
      inc(kg2);g2[kg2]:=y;p2[kg2]:=z;pred2[kg2]:=last2[x];last2[x]:=kg2;
    end;
  end;
  ans:=0;
  dfs2(1,0);
  writeln(ans/(n-1):0:10);
end.