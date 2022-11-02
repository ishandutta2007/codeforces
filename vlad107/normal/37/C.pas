{$r-,q-,s-,i-,o+}
var
  kg,o,i,j,tmp,n:longint;
  nom,l:array[0..100500]of longint;
  was:array[0..1000500]of boolean;
  g:array[0..1000500,0..2]of longint;
  r:array[0..1111]of ansistring;
  function dfs(x,k:longint;s:ansistring):boolean;
    var
      ch:longint;
    begin
      if (was[x])then begin
        dfs:=false;
        exit;
      end;
      if (k=0)then begin
        r[nom[o]]:=s;
        was[x]:=true;
        dfs:=true;
        exit;
      end;
      ch:=random(2);
      if (g[x][ch]=0)then begin
        inc(kg);
        g[x][ch]:=kg;
      end;
      if (dfs(g[x][ch],k-1,s+chr(ch+48)))then begin
        dfs:=true;
        exit;
      end;
      ch:=1-ch;
      if (g[x][ch]=0)then begin
        inc(kg);
        g[x][ch]:=kg;
      end;
      if (dfs(g[x][ch],k-1,s+chr(ch+48)))then begin
        dfs:=true;
        exit;
      end;
      was[x]:=true;
      dfs:=false;
    end;
begin
  randomize;
  readln(n);
  for i:=1 to n do read(l[i]);
  for i:=1 to n do nom[i]:=i;
  for i:=1 to n-1 do
    for j:=1 to n-1 do
      if (l[j]>l[j+1])then begin
        tmp:=l[j];l[j]:=l[j+1];l[j+1]:=tmp;
        tmp:=nom[j];nom[j]:=nom[j+1];nom[j+1]:=tmp;
      end;
  fillchar(was,sizeof(was),false);
  fillchar(g,sizeof(g),$0);
  kg:=0;
  for o:=1 to n do
    if (not dfs(0,l[o],''))then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
  for i:=1 to n do writeln(r[i]);
end.