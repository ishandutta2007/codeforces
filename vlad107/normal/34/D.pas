const
  MAXN=100000;
var
  x,n,r1,r2,i,j:longint;
  pred,g,last,prx:array[1..MAXN]of longint;
  procedure dfs(x,px:longint);
    var
      ii:longint;
    begin
      ii:=last[x];
      prx[x]:=px;
      while (ii>0)do begin
        if (g[ii]=px)then begin
          ii:=pred[ii];
          continue;
        end;
        dfs(g[ii],x);
        ii:=pred[ii];
      end;
    end;
begin
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  read(n,r1,r2);
  j:=0;
  for i:=1 to n do begin
    if (i=r1)then continue;
    inc(j);
    read(x);
    g[i+i-1]:=i;pred[i+i-1]:=last[x];last[x]:=i+i-1;
    g[i+i]:=x;pred[i+i]:=last[i];last[i]:=i+i;
  end;
  dfs(r2,0);
  for i:=1 to n do
    if (i<>r2)then write(prx[i],' ');
  writeln;
end.