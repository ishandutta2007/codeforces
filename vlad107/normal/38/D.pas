{$r-,q-,s-,i-,o+}
var
  res,i,n,j,q:longint;
  tx,ty,tsum:double;
  x1,y1,x2,y2,z1,z2,m:array[0..111]of longint;
  x,y,z:array[0..111]of double;
  ok:boolean;
   
begin
  read(n);
  z1[0]:=0;z2[0]:=0;
  for i:=1 to n do begin
    read(x1[i],y1[i],x2[i],y2[i]);
    if (x1[i]>x2[i])then begin
      q:=x1[i];x1[i]:=x2[i];x2[i]:=q;
    end;
    if (y1[i]>y2[i])then begin
      q:=y1[i];y1[i]:=y2[i];y2[i]:=q;
    end;
    z1[i]:=z2[i-1];
    z2[i]:=z1[i]+x2[i]-x1[i];
    x[i]:=(x1[i]+x2[i])/2;
    y[i]:=(y1[i]+y2[i])/2;
    z[i]:=(z1[i]+z2[i])/2;
    m[i]:=(x2[i]-x1[i])*(y2[i]-y1[i])*(z2[i]-z1[i]);  
  end;
  res:=1;
  for i:=1 to n do begin
    ok:=true;
    for j:=1 to i-1 do begin
      tsum:=0;
      tx:=0;
      ty:=0;
      for q:=j+1 to i do begin
        tsum:=tsum+m[q];
	tx:=tx+x[q]*m[q];
	ty:=ty+y[q]*m[q];
      end;
      tx:=tx/tsum;
      ty:=ty/tsum;
      if (tx<x1[j])or(ty<y1[j])or(tx>x2[j])or(ty>y2[j])
        then begin
          ok:=false;
	  break;
	end;
    end;
    if (ok)then res:=i else break;
  end;
  writeln(res);
end.