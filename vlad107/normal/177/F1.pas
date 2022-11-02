{$r-,q-,s-,i-,o+}
var
  j,n,k,t,kt,i,x,y,z,ko:longint;
  po,ax,ay,az:array[0..500500]of longint;
  a:array[0..1111,0..1111]of longint;
  ux,uy:array[0..500500]of boolean;
  
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
    
    begin
      i:=l;j:=r;
      xx:=po[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>po[i])do inc(i);
        while (xx<po[j])do dec(j);
        if (i>j)then break;
        tmp:=po[i];po[i]:=po[j];po[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

  procedure rec(x,o:longint);
    begin
      if (x>kt)then begin
        inc(ko);
        po[ko]:=o;
        exit;
      end;
      rec(x+1,o);
      if (not ux[ax[x]])and(not uy[ay[x]])then begin
        ux[ax[x]]:=true;
        uy[ay[x]]:=true;
        rec(x+1,o+az[x]);
        ux[ax[x]]:=false;
        uy[ay[x]]:=false;
      end;
    end;

begin
  read(n,k,t);
  fillchar(a,sizeof(a),$0);
  kt:=k;
  for i:=1 to k do begin
    read(ax[i],ay[i],az[i]);
    //inc(a[x][y],z);
  end;
{  for i:=1 to n do 
    for j:=1 to n do begin  
      inc(kt);
      ax[kt]:=i;
      ay[kt]:=j;
      az[kt]:=a[i][j];
    end;}
  fillchar(ux,sizeof(ux),false);
  fillchar(uy,sizeof(uy),false);
  rec(1,0);
  qs(1,ko);
  writeln(po[t]);
end.