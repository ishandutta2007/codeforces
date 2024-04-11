{$r-,q-,s-,i-,o+}
type
  TGraph=record
    p,g,pred,last:array[0..500500]of longint;
    kg:longint;
  end;

var
  dg,g:TGraph;
  tk,m,k,x,n,i,j:longint;
  kol,ans:array[0..500500]of longint;
  prx:array[0..100500,0..17]of longint;
  
  procedure addg(x,y:longint);
    begin
      inc(g.kg);
      g.g[g.kg]:=y;
      g.pred[g.kg]:=g.last[x];
      g.last[x]:=g.kg;
    end;
    
  procedure adddg(x,y,nom:longint);
    begin
      inc(dg.kg);
      dg.g[dg.kg]:=y;
      dg.p[dg.kg]:=nom;
      dg.pred[dg.kg]:=dg.last[x];
      dg.last[x]:=dg.kg;
    end;

  procedure dfs(x,dep:longint);
    var
      nom,ii,y:longint;
      
    begin
      inc(kol[dep]);
      ii:=dg.last[x];
      while (ii>0)do begin
        y:=dg.g[ii];
        nom:=dg.p[ii];
        ans[nom]:=-kol[dep+y];
        ii:=dg.pred[ii];
      end;
      ii:=g.last[x];      
      while (ii>0)do begin
        y:=g.g[ii];
        dfs(y,dep+1);
        ii:=g.pred[ii];
      end;
      ii:=dg.last[x];
      while (ii>0)do begin
        y:=dg.g[ii];
        nom:=dg.p[ii];
        ans[nom]:=ans[nom]+kol[dep+y];
        ii:=dg.pred[ii];
      end;
    end;
    
  procedure dfs2(x,dep:longint);
    var
      y,ii:longint;
      
    begin
      kol[dep]:=0;
      ii:=g.last[x];
      while (ii>0)do begin
        y:=g.g[ii];
        dfs(y,dep+1);
        ii:=g.pred[ii];
      end;
    end;
    
begin
  //assign(input,'input.txt');reset(input);
  randomize;
  read(n);
  for i:=1 to n do begin
    read(prx[i][0]);
    if (prx[i][0]<>0)then addg(prx[i][0],i);
  end;
  for j:=1 to 17 do 
    for i:=1 to n do 
      prx[i][j]:=prx[prx[i][j-1]][j-1];
  read(m);
  for i:=1 to m do begin
    read(x,k);
    tk:=k;
    for j:=17 downto 0 do 
      if (1 shl j<=k)then begin
        dec(k,1 shl j);
        x:=prx[x][j];
      end;
    if (x=0)then begin
      ans[i]:=1;
      continue;
    end;
    adddg(x,tk,i);
  end;
  for i:=1 to n do 
    if (prx[i][0]=0)then begin
      dfs(i,0);
      dfs2(i,0);
    end;
  for i:=1 to m do write(ans[i]-1,' ');
  writeln;
end.