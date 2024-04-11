{$r-,q-,s-,i-,o+}
const
  inf=1000000000;

var
  last,min,nom,ans,t,tmp,x,kg,sum,n,i,j:longint;
  used:array[0..500500]of boolean;
  kol,kol2,a,q:array[0..500500]of longint;
  d:array[0..555,0..555]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  fillchar(d,sizeof(d),$0);
  for i:=1 to n do begin
    read(kg);
    for j:=1 to kg do begin
      read(x);
      d[x][i]:=1;
      inc(kol2[i]);
    end;
  end;
  ans:=inf;
  for i:=1 to n do begin
    if (kol2[i]<>0)then continue;
    for j:=1 to n do kol[j]:=kol2[j];
    for j:=1 to n do used[j]:=false;
    sum:=0;
    used[i]:=true;
    last:=i;
    for j:=1 to n do 
      if (d[i][j]=1)then dec(kol[j]);
    for j:=1 to n-1 do begin
      min:=inf;
      nom:=0;
      for x:=1 to n do 
        if (not used[x])and((a[x]-a[last]+9)mod 3<min)and(kol[x]=0)then begin
          nom:=x;
          min:=(a[x]-a[last]+9)mod 3;
        end;
      if (nom=0)then begin
        sum:=inf;
        break;
      end;
      last:=nom;
      used[nom]:=true;
      sum:=sum+min;
      for x:=1 to n do 
        if (d[nom][x]=1)then dec(kol[x]);
    end;
    if (sum<ans)then ans:=sum;
  end;
  writeln(ans+n);
end.