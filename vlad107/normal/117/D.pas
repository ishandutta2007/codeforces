{$r-,q-,s-,i-,o+}
{$M 10000000}
var
  minl,maxl,uu,vv,l,r,n:int64;
  i,tt,base:longint;
  st2:array[0..66]of int64;

  function min(x,y:int64):int64;
    begin
      if (x<y)then min:=x else min:=y;
    end;

  function max(x,y:int64):int64;
    begin
      if (x>y)then max:=x else max:=y;
    end;

  function mul(a,b:int64):int64;
    begin
      if (a<0)then a:=(a+int64(1000000000)*base) mod base;
      if (b<0)then b:=(b+int64(1000000000)*base) mod base;
      a:=a mod base;
      b:=b mod base;
      mul:=a*b mod base;
    end;

  function sum(n:int64):int64;
    begin
      if (n mod 2=0)
        then sum:=mul(n div 2,n+1)
        else sum:=mul(n,(n+1)div 2);
    end;

  function find(l,r,lx,rx,t:int64;k:longint):int64;
    var
      u,v,sx,fx,nt,mid,res,q:int64;

    begin
      if (l=lx)and(r=rx)then begin
        //sum A:u-t<=X*2^k<=v-t
        u:=uu;
        v:=vv;
        minl:=t;
        maxl:=(n-t)div st2[k];//X*2^k<=n-t
        maxl:=maxl*st2[k]+t;
        if (u>maxl)or(v<minl)then begin
          find:=0;
          exit;
        end;
        if (u<minl)then u:=minl;
        if (v>maxl)then v:=maxl;
        u:=u-t;v:=v-t;
        fx:=v div st2[k];
        if (u<=0)then sx:=0 else begin
          sx:=u div st2[k];
          if (u mod st2[k]<>0)then sx:=sx+1;
        end;
        if (sx>fx)then begin
          find:=0;
          exit;
        end;
        res:=mul(t,fx-sx+1);
        res:=res+mul(sum(fx)-sum(sx-1),st2[k]);
        find:=res mod base;
        exit;
      end;
      mid:=(l+r)div 2;
      res:=0;
      nt:=t;
      if (nt=0)then nt:=st2[k];
      q:=(nt div st2[k])mod 2;
      nt:=t;
      if (q=1)then nt:=nt+st2[k];
      if (lx<=mid)then res:=res+find(l,mid,lx,min(rx,mid),nt,k+1);
      nt:=t;
      if (q=0)then nt:=nt+st2[k];
      if (rx>mid)then res:=res+find(mid+1,r,max(lx,mid+1),rx,nt,k+1);
      find:=res mod base;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,tt,base);
  st2[0]:=1;
  for i:=1 to 62 do st2[i]:=st2[i-1]+st2[i-1];

  while (tt>0)do begin
    dec(tt);
    read(l,r,uu,vv);
    writeln(find(1,n,l,r,0,0));
  end;
  close(output);close(input);
end.