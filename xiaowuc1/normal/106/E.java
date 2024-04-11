import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class E {
    static int[] x,y,z;
    public static void main(String[] args) throws IOException   {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        x = new int[n];
        y = new int[n];
        z = new int[n];
        double bestX = 0;
        double bestY = 0;
        double bestZ = 0;
        for(int i = 0; i < n; i++)  {
            StringTokenizer st = new StringTokenizer(br.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
            z[i] = Integer.parseInt(st.nextToken());
            bestX += x[i];
            bestY += y[i];
            bestZ += z[i];
        }
        double scale = 0.2;
        for(int i = 0; i < 100000; i++) {
            double go = 0;
            int worst = 0;
            for(int k = 0; k < n; k++)  {
                double check = dist(bestX,bestY,bestZ,x[k],y[k],z[k]);
                if(check>go)        {
                    go=check;
                    worst=k;
                }
            }
            bestX += (x[worst]-bestX)*scale;
            bestY += (y[worst]-bestY)*scale;
            bestZ += (z[worst]-bestZ)*scale;
            scale *= 0.999;
        }
        System.out.println(bestX + " " + bestY + " " + bestZ);
    }
    public static double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
        double x = x1-x2;
        double y = y1-y2;
        double z = z1-z2;
        return x*x+y*y+z*z;
    }
}