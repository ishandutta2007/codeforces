{$r-,q-,s-,i-,o+}
const 
  hx:array[1..4]of longint=(1,0,-1,0);
  hy:array[1..4]of longint=(0,1,0,-1);
var
  qqq,cx,cy,qb,qe,x,y,kn,x1,y1,x2,y2,t,t2,i,j,n,m,ker:longint;
  a,b:array[0..1111,0..1111]of char;
  g:array[0..1111,0..1111]of longint;
  rev,qx,qy,xer,yer:array[0..1005000]of longint;
  used:array[0..100]of longint;
  function ok(x,y:longint):boolean;
    var
      cx,cy,i:longint;
    begin
      for i:=1 to 4 do begin
        cx:=x+hx[i];
        cy:=y+hy[i];
        if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
        if (a[cx][cy]='#')then continue;
        ok:=true;
        exit;
      end;
      ok:=false;
    end;
  procedure okok(x,y:longint);
    var
      i,cx,cy:longint;
    begin
      for i:=1 to 4 do begin
        cx:=x+hx[i];
        cy:=y+hy[i];
	    if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
	    if (a[cx][cy]='#')then continue;
	    if (ok(cx,cy))then continue;
	    inc(ker);
	    xer[ker]:=cx;
	    yer[ker]:=cy;
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  fillchar(g,sizeof(g),$0);
  b:=a;
  for i:=1 to n do 
    for j:=1 to m do 
      if (a[i][j]='.')and(not ok(i,j))then begin
        writeln(-1);
        exit;
      end;
  kn:=0;
  for i:=1 to n do 
    for j:=1 to m do 
      if (a[i][j]='.')then begin
        x1:=i;y1:=j;
        for t:=1 to 4 do begin
          x2:=i+hx[t];
          y2:=j+hy[t];
          if (x2<1)or(y2<1)or(x2>n)or(y2>m)then continue;
          if (a[x2][y2]='#')then continue;
          inc(kn);
          g[x1][y1]:=kn;
          g[x2][y2]:=kn;
          a[x1][y1]:='#';
          a[x2][y2]:='#';
          ker:=0;
          okok(x1,y1);
          okok(x2,y2);
          if (ker+2>5)then begin
            g[x1][y1]:=0;
            g[x2][y2]:=0;
            a[x1][y1]:='.';
            a[x2][y2]:='.';
          end;
          for t2:=1 to ker do begin
            a[xer[t2],yer[t2]]:='#';
            g[xer[t2],yer[t2]]:=kn;
          end;
          break;
        end;
      end;
  fillchar(rev,sizeof(rev),$FF);
  qqq:=0;
  fillchar(used,sizeof(used),$0);
  a:=b;
  for i:=1 to n do begin
    for j:=1 to m do 
      if (b[i][j]='#')
        then write(b[i][j])
        else begin
          if (rev[g[i][j]]=-1)
            then begin
              inc(qqq);
              qb:=0;qe:=1;
              qx[1]:=i;qy[1]:=j;
              while (qb<qe)do begin
                inc(qb);
                x:=qx[qb];
                y:=qy[qb];
                for t:=1 to 4 do begin
                  cx:=x+hx[t];
                  cy:=y+hy[t];
                  if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
                  if (b[cx][cy]='#')then continue;
                  if (g[i][j]=g[cx][cy])then begin
                    if (a[cx][cy]='#')then continue;
                    a[cx][cy]:='#';
                    inc(qe);
                    qx[qe]:=cx;
                    qy[qe]:=cy;
                    continue;
                  end;
                  if (rev[g[cx][cy]]=-1)then continue;
                  used[rev[g[cx][cy]]]:=qqq;
                end;
              end;
              t:=0;
              while (used[t]=qqq)do inc(t);
              rev[g[i][j]]:=t;
            end;
          write(rev[g[i][j]]);
        end;
    writeln;
  end;
  close(output);close(input);
end.