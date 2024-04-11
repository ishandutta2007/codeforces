var
  first:boolean;
  kt,i,ii,x,y,kg,n,m,k:longint;
  g,pred,a,last:array[0..500500]of longint;
  used:array[0..500500]of boolean;

begin
  read(n,m,k);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  fillchar(used,sizeof(used),false);
  used[1]:=true;
  a[1]:=1;
  k:=n;
  for i:=2 to n do begin
    ii:=last[a[i-1]];
    a[i]:=-1;
    while (ii>0)do begin
      y:=g[ii];
      if (not used[y])then begin
        used[y]:=true;
        a[i]:=y;
        break;
      end;
      ii:=pred[ii];
    end;
    if (a[i]<0)then begin
      k:=i-1;
      break;
    end;
  end;
  fillchar(used,sizeof(used),false);
  ii:=last[a[k]];
  while (ii>0)do begin
    used[g[ii]]:=true;
    ii:=pred[ii];
  end;
  first:=true;
  kt:=0;
  for i:=1 to k do begin
    if (used[a[i]])then first:=false;
    if (not first)then inc(kt);
  end;
  writeln(kt);
  first:=true;
  for i:=1 to k do begin
    if (used[a[i]])then first:=false;
    if (not first)then write(a[i],' ');
  end;
end.