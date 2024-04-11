{$r+,q+,s+,i+,o-}
const
  mbase=10000019;

var
  g,pred,last:array[0..1050000]of longint;
  tpred:array[0..2005000]of longint;
  tg:array[0..2005000]of int64;
  tlast:array[0..mbase+10]of longint;
  kol,nom,t:array[0..1000500]of longint;
  n,m,ii,x,y,kg,knom,tkg,i,kt:longint;
  
  procedure add(x:int64);
    var
      tx:longint;
      
    begin
      tx:=x mod mbase;
      inc(tkg);
      tg[tkg]:=x;
      tpred[tkg]:=tlast[tx];
      tlast[tx]:=tkg;
    end;
    
  function find(x:int64):boolean;
    var
      tx,ii:longint;
      
    begin
      tx:=x mod mbase;
      ii:=tlast[tx];
      while (ii>0)do begin
        if (tg[ii]=x)then begin
          find:=true;
          exit;
        end;
        ii:=tpred[ii];
      end;
      find:=false;
    end;

  procedure dfs(x:longint);
    var
      y,i:longint;
      
    begin
      i:=1;
      while (i<=kt)do begin
        y:=t[i];
        if (find(int64(x)*(n+1)+y))then begin
          inc(i);
          continue;
        end;
        nom[y]:=knom;
        t[i]:=t[kt];
        dec(kt);
        dfs(y);
        i:=1;
      end;
    end;

begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y);
    add(int64(x)*(n+1)+y);
    add(int64(y)*(n+1)+x);
  end;
  for i:=1 to n do t[i]:=i;
  kt:=n;
  while (kt>0)do begin
    inc(knom);
    x:=t[1];
    t[1]:=t[kt];
    dec(kt);
    nom[x]:=knom;
    dfs(x);
  end;
  writeln(knom);
  for i:=1 to n do begin
    inc(kg);
    g[kg]:=i;
    pred[kg]:=last[nom[i]];
    last[nom[i]]:=kg;
    inc(kol[nom[i]]);
  end;
  for i:=1 to knom do begin
    write(kol[i]);
    ii:=last[i];
    while (ii>0)do begin
      x:=g[ii];
      write(' ',x);
      ii:=pred[ii];
    end;
    writeln;
  end;
end.