const
  maxn=700500;
var
  used:array[0..maxn]of boolean;
  was,t,pred2,g2,last2,pred,g,last:array[0..maxn]of longint;
  kt,n,m,i,j,x,y,ii,kg,kg2:longint;

  procedure dfs(x,px:longint);
    var
      ii,y:longint;

    begin
      was[x]:=1;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (y<>px)and(was[y]<>2)then begin
          inc(kg2);
          g2[kg2]:=y;
          pred2[kg2]:=last2[x];
          last2[x]:=kg2;

          if (was[y]=0)then dfs(y,x);
        end;
        ii:=pred[ii];
      end;
      was[x]:=2;
    end;

  procedure dfs1(x:longint);
    var
      ii,y:longint;

    begin
      used[x]:=true;
      ii:=last2[x];
      while (ii>0)do begin
        y:=g2[ii];
        if (not used[y])then dfs1(y);
        ii:=pred2[ii];
      end;
      inc(kt);
      t[kt]:=x;
    end;

  procedure dfs2(x:longint);
    var
      y,ii:longint;

    begin
      used[x]:=true;
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        if (not used[y])then dfs2(y);
        ii:=pred[ii];
      end;
    end;

begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;

  fillchar(used,sizeof(used),false);
  fillchar(was,sizeof(was),$0);
  dfs(1,0);

  kg:=kg2;
  for i:=1 to maxn do begin
    pred[i]:=pred2[i];
    g[i]:=g2[i];
    last[i]:=last2[i];
  end;

  fillchar(last2,sizeof(last2),$0);
  fillchar(pred2,sizeof(pred2),$0);
  fillchar(g2,sizeof(g2),$0);
  kg2:=0;
  for i:=1 to n do begin
    ii:=last[i];
    while (ii>0)do begin
      y:=g[ii];

      inc(kg2);
      g2[kg2]:=i;
      pred2[kg2]:=last2[y];
      last2[y]:=kg2;

      ii:=pred[ii];
    end;
  end;

  kt:=0;
  fillchar(used,sizeof(used),false);
  for i:=1 to n do
    if (not used[i])then dfs1(i);

  fillchar(used,sizeof(used),false);
  dfs2(t[kt]);
  for i:=1 to n do
    if (not used[i])then begin
      writeln(0);
      exit;
    end;
  for x:=1 to n do begin
    ii:=last[x];
    while (ii>0)do begin
      writeln(x,' ',g[ii]);
      ii:=pred[ii];
    end;
  end;
end.