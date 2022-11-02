{$r-,q-,s-,i-,o+}
const
  baseh=1000003;
  inf=1000000000;
var
  min,x,y,z,n,m,k,i,ii,qb,qe,kgh:longint;
  pd,q,d,r,predh,gh,pred,last,ss,ff,lasth:array[0..2000000]of longint;
  nome:array[0..3030,0..3030]of longint;
  function find(x:longint):boolean;
    var
      ii:longint;
    begin
      ii:=lasth[x mod baseh];
      while (ii>0)do begin
        if (gh[ii]=x)then begin
          find:=true;
          exit;
        end;
        ii:=predh[ii];
      end;
      find:=false;
      exit;
    end;
begin
  read(n,m,k);
  for i:=1 to m do begin
    read(ss[i],ff[i]);
    ff[i+m]:=ss[i];
    ss[i+m]:=ff[i];
  end;
  kgh:=0;
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  fillchar(predh,sizeof(predh),$0);
  fillchar(lasth,sizeof(lasth),$0);
  for i:=1 to m+m do begin
    pred[i]:=last[ss[i]];last[ss[i]]:=i;
    nome[ss[i]][ff[i]]:=i;
  end;
  for i:=1 to k do begin
    read(x,y,z);
    x:=nome[x][y];
    x:=x*3001+z;
    y:=x mod baseh;
    inc(kgh);
    gh[kgh]:=x;
    predh[kgh]:=lasth[y];
    lasth[y]:=kgh;
  end;
  ii:=last[1];
  qb:=0;qe:=0;
  for i:=1 to m+m do d[i]:=inf;
  while (ii>0)do begin
    x:=nome[1,ff[ii]];
    d[x]:=2;
    inc(qe);
    q[qe]:=x;
    ii:=pred[ii];
  end;
  while (qb<qe)do begin
    inc(qb);
    x:=q[qb];
    ii:=last[ff[x]];
    while (ii>0)do begin
      y:=ff[ii];
      if (not find(x*3001+y))and(d[ii]>d[x]+1)then begin
        d[ii]:=d[x]+1;
        pd[ii]:=x;
        inc(qe);q[qe]:=ii;
      end;
      ii:=pred[ii];
    end;
  end;
  min:=inf;
  for i:=1 to m+m do 
    if (ff[i]=n)and(d[i]<min)then begin
      min:=d[i];
      x:=i;
    end;
  if (min=inf)then begin
    writeln(-1);
    exit;
  end;
  writeln(d[x]-1);
  ii:=2;
  r[1]:=n;
  r[2]:=ss[x];
  while (ss[x]<>1)do begin
    x:=pd[x];
    inc(ii);
    r[ii]:=ss[x];
  end;
  for i:=1 to ii do write(r[ii+1-i],' ');
  writeln;
end.