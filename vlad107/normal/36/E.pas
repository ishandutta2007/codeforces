{$r-,q-,s-,i-,o+}
var
  ss,j,n,m,x,y,i,kg,kr,kb,kt:longint;
  used,ft:array[0..500500]of boolean;
  nom,deg,r,g,pred,last,p:array[0..500500]of longint;
  
  procedure dfs2(x:longint);
    var
      ii:longint;
    begin
      ii:=last[x];
      while (ii>0)do begin
        if (not used[p[ii]])then begin
          used[p[ii]]:=true;
          dfs2(g[ii]);
          inc(kr);
          r[kr]:=p[ii];
        end;
        ii:=pred[ii];
      end;
    end;

  procedure dfs(x:longint);
    var
      ii:longint;
    begin
      if (nom[x]>0)then exit;
      nom[x]:=kt;
      ii:=last[x];
      while (ii>0)do begin
        dfs(g[ii]);
        ii:=pred[ii];
      end;
    end;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  fillchar(used,sizeof(used),false);
  read(m);
  n:=10000;
  for i:=1 to m do begin
    read(x,y);
    inc(deg[x]);
    inc(deg[y]);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;p[kg]:=i;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;p[kg]:=i;
  end;
  kb:=0;
  fillchar(nom,sizeof(nom),$ff);
  for i:=1 to n do begin
    if (deg[i]=0)then continue;
    ss:=i;
    if (nom[i]<0)then begin
      inc(kt);
      dfs(i);
    end;
    if (deg[i] and 1=1)then begin
      inc(kb);
      ft[nom[i]]:=true;
    end;
  end;
  if (m=1)or(kt>2)or(kb>4)or((kt=2)and(kb=4)and(not(ft[1]and ft[2])))then begin writeln(-1);exit; end;
  kr:=0;
  if (kt=1)then begin
    if (kb=4)then begin
      x:=-1;y:=-1;
      for i:=1 to n do 
        if (deg[i] and 1=1)then begin
          if (x<0)then x:=i else
          if (y<0)then y:=i else begin
            inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;p[kg]:=m+1;
            inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;p[kg]:=m+1;
            dfs2(i);
            break;
          end;
        end;
      i:=1;
      while (r[i]<=m)do inc(i);
      writeln(i-1);
      for j:=1 to i-1 do write(r[j],' ');
      writeln;
      writeln(m+1-i);
      for j:=i+1 to m+1 do write(r[j],' ');
      writeln;
      exit;
    end;
    if (kb=2)then begin
      ss:=1;
      while (deg[ss] and 1=0)do inc(ss);
    end;
    dfs2(ss);
    writeln(1);
    writeln(r[1]);
    writeln(m-1);
    for i:=2 to m do write(r[i],' ');
    writeln;
    exit;
  end;
  x:=-1;y:=-1;
  for i:=1 to n do 
    if (nom[i]=1)and((x<0)or(deg[i] and 1=1))then x:=i else
    if (nom[i]=2)and((y<0)or(deg[i] and 1=1))then y:=i;
  dfs2(x);
  writeln(kr);
  for i:=1 to kr do write(r[i],' ');
  writeln;
  kr:=0;
  dfs2(y);
  writeln(kr);
  for i:=1 to kr do write(r[i],' ');
  writeln;
  close(output);close(input);
end.