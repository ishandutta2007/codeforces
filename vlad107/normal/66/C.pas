var
  kol,kl:array[0..100000]of longint;
  g:array[0..10000,0..10000]of boolean;
  ss:array[0..100000]of string;
  r1,r2,o,n,i,x,px:longint;
  t,s:string;
  procedure dfs(x,px:longint);
    var
      i:longint;
    begin
      kol[x]:=1;
      kl[x]:=0;
      for i:=1 to n do
        if (g[x][i])and(i<>px)then begin
          dfs(i,x);
          kol[x]:=kol[x]+kol[i];
          kl[x]:=kl[x]+kl[i];
        end;
      if (kol[x]=1)then kl[x]:=1;
      if (kol[x]-kl[x]>r1)then r1:=kol[x]-kl[x];
      if (kl[x]>r2)then r2:=kl[x];
    end;
  function findnom(s:string):longint;
    var
      i:longint;
    begin
      i:=1;
      while (i<=n)and(s<>ss[i])do inc(i);
      if (i>n)then begin
        inc(n);
        ss[n]:=s;
      end;
      findnom:=i;
    end;
begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  n:=0;
  while (not eof(input))do begin
    readln(s);
    i:=4;
    t:=s;
    delete(t,1,3);
    if (pos('\',t)=0)then continue;
    px:=0;
    while (pos('\',t)>0)do begin
      o:=pos('\',t);
      delete(t,1,o);
      while (s[i]<>'\')do inc(i);
      x:=findnom(copy(s,1,i));
      if (px>0)then g[px][x]:=true;
      px:=x;
      inc(i);
    end;
    x:=findnom(t);
    if (px>0)then g[px][x]:=true;
  end;
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to n do
    if (kol[i]=0)then dfs(i,0);
  if (r1=0)then r1:=1;
  writeln(r1-1,' ',r2);
end.