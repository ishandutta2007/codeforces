{$r-,q-,s-,i-,o+}
var
  kg,kt,n,m,x,y,t,i,j:longint;
  q,g,pred,last,ot:array[0..500500]of longint;
  
  function o(x,t:longint):longint;
    begin
      if (t=0)
        then o:=x
        else o:=x+n;
    end;

  procedure add(x,y:longint);
    begin
      inc(kg);
      g[kg]:=y;
      pred[kg]:=last[x];
      last[x]:=kg;
      
      inc(kg);
      g[kg]:=x;
      pred[kg]:=last[y];
      last[y]:=kg;
    end;
    
  function dfs(x:longint):boolean;
    var
      ty,ii,y:longint;
      
    begin
      inc(kt);ot[kt]:=x;
      ii:=last[o(x,q[x])];
      while (ii>0)do begin
        y:=g[ii];
        ty:=0;
        if (y>n)then begin
          dec(y,n);
          ty:=1;
        end;
        if (q[y]<>-1)and(q[y]<>ty)then begin
          dfs:=false;
          exit;
        end;
        if (q[y]=-1)then begin
          q[y]:=ty;
          if (not dfs(y))then begin
            dfs:=false;
            exit;
          end;
        end;
        ii:=pred[ii];
      end;
      dfs:=true;
    end;

begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y,t);
    if (t=0)then begin
      add(x,y+n);
      add(x+n,y);
    end;
    if (t=1)then begin
      add(x,y);
      add(x+n,y+n);
    end;
  end;
  fillchar(q,sizeof(q),$FF);
  for i:=1 to n do begin
    if (q[i]<>-1)then continue;
    q[i]:=0;
    kt:=0;
    if (not dfs(i))then for j:=1 to kt do q[ot[j]]:=-1;
    if (q[i]<>-1)then continue;
    q[i]:=1;
    kt:=0;
    if (not dfs(i))then for j:=1 to kt do q[ot[j]]:=-1;
    if (q[i]=-1)then begin
      writeln('Impossible');
      exit;
    end;
  end;
  x:=0;
  for i:=1 to n do 
    if (q[i]=1)then inc(x);
  writeln(x);
  for i:=1 to n do
    if (q[i]=1)then write(i,' ');
  writeln;
end.