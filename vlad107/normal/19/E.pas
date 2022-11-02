{$r-,q-,s-,i-,o+}
var
  tmp,x,y,tx,ty,ka,n,m,i,kst:longint;
  good:boolean;
  pred,dist,a,ss,ff:array[0..50500]of longint;
  st1,st2,st3:array[0..2000000]of longint;
  procedure findset(x:longint;var px,dx:longint);
    begin
      if (pred[x]<>x)then begin
        findset(pred[x],px,dx);
        dx:=dx xor dist[x];
        inc(kst);
        st1[kst]:=x;
        st2[kst]:=pred[x];
        st3[kst]:=dist[x];
        pred[x]:=px;
        dist[x]:=dx;
        exit;
      end;
      px:=x;
      dx:=0;
    end;
  procedure rec(l,r:longint);
    var
      i,mid:longint;
    begin
      if (not good)then exit;
      if (l=r)then begin
        inc(ka);
        a[ka]:=l;
        exit;
      end;
      mid:=(l+r)shr 1;
      inc(kst);
      st1[kst]:=-1;
      for i:=mid+1 to r do begin
        findset(ss[i],x,tx);
        findset(ff[i],y,ty);
        if (x=y)
          then begin
            if (tx=ty)then begin
              good:=false;
              break;
            end;
          end else begin
            if (random(maxlongint)and 1=1)then begin
              tmp:=x;x:=y;y:=tmp;
            end;
            inc(kst);
            st1[kst]:=y;
            st2[kst]:=pred[y];
            st3[kst]:=dist[y];
            pred[y]:=x;
            dist[y]:=tx xor ty xor 1;
          end;
      end;
      rec(l,mid);
      good:=true;
      while (st1[kst]<>-1)do begin
        pred[st1[kst]]:=st2[kst];
        dist[st1[kst]]:=st3[kst];
        dec(kst);
      end;
      
      for i:=l to mid do begin
        findset(ss[i],x,tx);
        findset(ff[i],y,ty);
        if (x=y)
          then begin
            if (tx=ty)then begin
              good:=false;
              break;
            end;
          end else begin
            if (random(maxlongint)and 1=1)then begin
              tmp:=x;x:=y;y:=tmp;
            end;
            inc(kst);
            st1[kst]:=y;
            st2[kst]:=pred[y];
            st3[kst]:=dist[y];
            pred[y]:=x;
            dist[y]:=tx xor ty xor 1;
          end;        
      end;
      rec(mid+1,r);
      good:=true;
      while (st1[kst]<>-1)do begin
        pred[st1[kst]]:=st2[kst];
        dist[st1[kst]]:=st3[kst];
        dec(kst);
      end;
      dec(kst);
    end;

begin
  randomize;
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n,m);
  if (m=0)then begin
    writeln(0);
    exit;
  end;
  for i:=1 to m do read(ss[i],ff[i]);
  for i:=1 to n do begin
    pred[i]:=i;
    dist[i]:=0;
  end;
  good:=true;
  kst:=0;
  rec(1,m);
  writeln(ka);
  for i:=1 to ka do write(a[i],' ');
  writeln;
  close(output);close(input);
end.