{$r-,q-,s-,i-,o+}
const
  inf=1000000000;

var
  qb,qe,x,ss,ff,ans,n,m,i,j,cost,flow:longint;
  t1:array[0..500500]of char;
  d,q,pr,s1,s2:array[0..500500]of longint;
  ch:char;
  p,c,du:array[0..555,0..555]of longint;
  
  procedure init;
    begin
      fillchar(p,sizeof(p),$0);
      fillchar(c,sizeof(c),$0);
      ss:=0;ff:=n+m+1;
      for i:=1 to m do 
        for j:=1 to n do begin 
          p[i][j+m]:=0;
          c[i][j+m]:=1;
          if (t1[j]='A')and(s2[i]>=s1[j])then du[i][j+m]:=s2[i]-s1[j] else
          if (t1[j]='D')and(s2[i]>s1[j])then du[i][j+m]:=0 else 
          du[i][j+m]:=-inf;
          du[j+m][i]:=-du[i][j+m];
        end;
      for i:=1 to m do begin
        du[ss][i]:=0;
        du[i][ss]:=0;
        p[ss][i]:=0;
        c[ss][i]:=1;
      end;
      for i:=1 to n do begin
        du[i+m][ff]:=0;
        du[ff][i+m]:=0;
        p[i+m][ff]:=0;
        c[i+m][ff]:=1;
      end;    
    end;
  
  function way:boolean;
    begin
      qb:=0;qe:=1;
      q[1]:=ss;
      d[0]:=0;
      for i:=1 to ff do d[i]:=-inf;
      while (qb<qe)do begin
        inc(qb);
        x:=q[qb];
        for i:=0 to ff do 
          if (p[x][i]<c[x][i])and(d[x]+du[x][i]>d[i])then begin
            d[i]:=d[x]+du[x][i];
            pr[i]:=x;
            inc(qe);
            q[qe]:=i;
          end;
      end;
      if (d[ff]=-inf)then begin
        way:=false;
        exit;
      end;
      way:=true;
      inc(flow);
      i:=ff;
      while (i<>ss)do begin
        inc(cost,du[pr[i]][i]);
        inc(p[pr[i]][i]);
        dec(p[i][pr[i]]);
        i:=pr[i];
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  readln(n,m);
  for i:=1 to n do readln(t1[i],ch,ch,s1[i]);
  for i:=1 to m do readln(s2[i]);
  ans:=0;
  init;
  cost:=0;flow:=0;
  while (way)do begin
    if (cost>ans)then ans:=cost;
  end;
  if (m>n)then begin
    for i:=n+1 to m do begin
      t1[i]:='A';
      s1[i]:=0;
    end;
    n:=m;
    init;
    cost:=0;flow:=0;
    while (way)do;
    if (flow=n)and(cost>ans)then ans:=cost;
  end;
  writeln(ans);
end.