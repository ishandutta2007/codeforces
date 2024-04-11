{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  kg,kt,uu,kst,n,m,x,y,i:longint;
  ans,cnt,pred,pr,prx,g,last,lt,pt,t:array[0..500500]of longint;
  pst,cst,st:array[0..2000000]of longint;

  procedure dfs0(x,px:longint);
    var
      y,ii:longint;
      
    begin
      prx[x]:=px;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then dfs0(y,x);
        ii:=pred[ii];
      end;
    end;
    
  procedure union(x,y:longint);
    var
      tmp:longint;
      
    begin
      inc(kst);
      st[kst]:=y;
      pst[kst]:=pr[y];
      cst[kst]:=cnt[y];
      inc(kst);
      st[kst]:=x;
      pst[kst]:=pr[x];
      cst[kst]:=cnt[x];
      if (random(maxlongint)and 1=0)then begin
        tmp:=x;x:=y;y:=tmp;
      end;
      pr[y]:=x;
      inc(cnt[x],cnt[y]);
    end;
    
  function fs(x:longint):longint;
    var
      ct:longint;
      
    begin
      if (pr[x]<>x)then begin
        ct:=fs(pr[x]);
        inc(kst);
        st[kst]:=x;
        pst[kst]:=pr[x];
        cst[kst]:=cnt[x];
        pr[x]:=ct;
      end;
      fs:=pr[x];
    end;
    
  procedure dfs2(x,px:longint);
    var
      c1,c2,y,ii:longint;
      
    begin
      c1:=fs(x);c2:=fs(uu);
      if (c1=c2)then exit;
      union(c1,c2);
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)then dfs2(y,x);
        ii:=pred[ii];
      end;
    end;

  procedure dfs1(x,px:longint);
    var
      ii,y:longint;
      
    begin
      inc(kst);
      st[kst]:=-1;
      if (lt[x]<>0)then begin
        ii:=last[x];
        while (ii>0)do begin
          y:=g[ii];
          if (y<>px)then begin
            uu:=x;
            dfs2(y,x);
          end;
          ii:=pred[ii];
        end;
      end;
      
      ii:=lt[x];
      while (ii>0)do begin
        y:=t[ii];
        uu:=x;
        dfs2(y,prx[y]);
        ii:=pt[ii];
      end;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
      if (y<>px)then dfs1(y,x);
        ii:=pred[ii];
      end;
      ans[x]:=cnt[fs(x)];
      while (st[kst]<>-1)do begin
        pr[st[kst]]:=pst[kst];
        cnt[st[kst]]:=cst[kst];
        dec(kst);
      end;
      dec(kst);
    end;

begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,m);
  for i:=1 to n-1 do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  for i:=1 to m do begin
    read(x,y);
    inc(kt);t[kt]:=y;pt[kt]:=lt[x];lt[x]:=kt;
    inc(kt);t[kt]:=x;pt[kt]:=lt[y];lt[y]:=kt;
  end;
  for i:=1 to n do pr[i]:=i;
  for i:=1 to n do cnt[i]:=1;
  dfs0(1,0);
  dfs1(1,0);
  for i:=1 to n do write(ans[i]-1,' ');
  writeln;
end.